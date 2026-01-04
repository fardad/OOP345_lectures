#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

using namespace std;
using ull = unsigned long long;
using clk = chrono::steady_clock;

void sum_range(promise<ull> sum_prom, ull beg, ull end) {
   ull total = 0;
   for (ull i = beg; i <= end; ++i) {
      total += i;
   }
   sum_prom.set_value(total);
}

int main() {
   ull beg = 0;
   ull end = 12'312'312'311ULL;   // large range

   // ---------------- Single-threaded sum ----------------
   auto st = clk::now();

   ull sm = 0;
   for (ull i = beg; i <= end; ++i) {
      sm += i;
   }

   cout << "Single-thread sum : " << sm << '\n';

   auto en = clk::now();
   auto duration = chrono::duration_cast<chrono::milliseconds>(en - st);
   cout << "Single-thread time: " << duration.count() << " ms\n\n";

   // ---------------- Multi-threaded sum ----------------
   unsigned int hw = thread::hardware_concurrency();
   if (hw == 0) hw = 4;               // fallback
   size_t numThreads = hw;

   cout << "Using " << numThreads << " threads.\n";

   // Prepare promises/futures and threads
   vector<promise<ull>> promises(numThreads);
   vector<future<ull>> futures;


   for (size_t i = 0; i < numThreads; ++i) {
      futures.emplace_back(promises[i].get_future());
   }

   vector<thread> threads;
   threads.reserve(numThreads);// nice to have

   // Split the range [beg, end] into numThreads chunks
   ull totalCount = end - beg + 1;
   ull chunkSize = totalCount / numThreads;
   ull leftover = totalCount % numThreads;

   st = clk::now();

   ull chunkBeg = beg;
   for (size_t i = 0; i < numThreads; ++i) {
      ull extra = (i < leftover) ? 1 : 0;   // spread remainder
      ull chunkEnd = chunkBeg + chunkSize + extra - 1;

      threads.emplace_back(
         sum_range,
         move(promises[i]),   // move promise into thread
         chunkBeg,
         chunkEnd
      );

      chunkBeg = chunkEnd + 1;
   }

   cout << "Math is being done!\n";

   // Collect results from futures
   ull parallelSum = 0;
   for (auto& fut : futures) {
      parallelSum += fut.get();      // wait for each chunk result
   }

   en = clk::now();
   duration = chrono::duration_cast<chrono::milliseconds>(en - st);

   cout << "Multi-thread sum  : " << parallelSum << '\n';
   cout << "Multi-thread time : " << duration.count() << " ms\n";

   for (auto& t : threads) {
      t.join();
   }

   return 0;
}
