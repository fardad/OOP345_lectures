#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

using namespace std;
using ull = unsigned long long;
using clk = chrono::steady_clock;

ull sum_range(ull beg, ull end) {
   ull total = 0;
   for (ull i = beg; i <= end; ++i) {
      total += i;
   }
   return total;
}

int main() {
   ull beg = 0;
   ull end = 22'312'312'311ULL;   // large range

   // ---------------- Single-threaded sum ----------------
   auto st = clk::now();

   ull singleSum = 0;
   for (ull i = beg; i <= end; ++i) {
      singleSum += i;
   }

   cout << "Single-thread sum : " << singleSum << '\n';

   auto en = clk::now();
   auto duration = chrono::duration_cast<chrono::milliseconds>(en - st);
   cout << "Single-thread time: " << duration.count() << " ms\n\n";

   // ---------------- Multi-threaded sum using async ----------------
   unsigned int hw = thread::hardware_concurrency();
   if (hw == 0) hw = 4;               // fallback if unknown
   size_t numThreads = hw;

   cout << "Using " << numThreads << " async tasks.\n";

   vector<future<ull>> futures;


   ull totalCount = end - beg + 1;
   ull chunkSize = totalCount / numThreads;
   ull leftover = totalCount % numThreads;

   st = clk::now();

   ull chunkBeg = beg;
   for (size_t i = 0; i < numThreads; ++i) {
      ull extra = (i < leftover) ? 1 : 0;   // spread remainder
      ull chunkEnd = chunkBeg + chunkSize + extra - 1;

      futures.emplace_back(
         async(launch::async, sum_range, chunkBeg, chunkEnd)
      );

      chunkBeg = chunkEnd + 1;
   }

   ull parallelSum = 0;
   for (auto& fut : futures) {
      parallelSum += fut.get();      // waits for each async task
   }

   en = clk::now();
   duration = chrono::duration_cast<chrono::milliseconds>(en - st);

   cout << "Multi-thread sum  : " << parallelSum << '\n';
   cout << "Multi-thread time : " << duration.count() << " ms\n";

   // Optional sanity check
   if (parallelSum == singleSum) {
      cout << "Results match.\n";
   }
   else {
      cout << "Mismatch! Something is wrong.\n";
   }

   return 0;
}
