#include <iostream>
#include <thread>
#include <future>
#include <chrono>

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
   ull end = 12'312'312'311ULL;   // big number, clearly 64-bit

   // --- Single-threaded sum ---
   auto st = clk::now();

   ull sm = 0;
   for (ull i = beg; i <= end; ++i) {
      sm += i;
   }

   cout << "Single-thread sum: " << sm << '\n';

   auto en = clk::now();
   auto duration = chrono::duration_cast<chrono::milliseconds>(en - st);
   cout << "Single-thread time: " << duration.count() << " ms\n\n";

   // --- Multi-threaded sum using promise/future ---
   promise<ull> sumPromise1;
   future<ull> sumFuture1 = sumPromise1.get_future();

   promise<ull> sumPromise2;
   future<ull> sumFuture2 = sumPromise2.get_future();

   promise<ull> sumPromise3;
   future<ull> sumFuture3 = sumPromise3.get_future();

   promise<ull> sumPromise4;
   future<ull> sumFuture4 = sumPromise4.get_future();

   st = clk::now();

   ull chunk = end / 4;

   thread t1(sum_range, move(sumPromise1), beg, chunk);
   thread t2(sum_range, move(sumPromise2), chunk + 1, chunk * 2);
   thread t3(sum_range, move(sumPromise3), chunk * 2 + 1, chunk * 3);
   thread t4(sum_range, move(sumPromise4), chunk * 3 + 1, end);

   cout << "Math is being done!\n";

   ull parallelSum =
      sumFuture1.get() +
      sumFuture2.get() +
      sumFuture3.get() +
      sumFuture4.get();

   cout << "Multi-thread sum: " << parallelSum << '\n';
   cout << "Done!\n";

   t1.join();
   t2.join();
   t3.join();
   t4.join();

   en = clk::now();
   duration = chrono::duration_cast<chrono::milliseconds>(en - st);
   cout << "Multi-thread time: " << duration.count() << " ms\n";

   return 0;
}
