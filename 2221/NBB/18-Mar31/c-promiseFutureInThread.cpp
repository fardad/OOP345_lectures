#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

typedef unsigned long long ull;

void sum(promise<ull>&& sp, ull beg, ull end) {
   ull s = 0, i;
   for (i = beg; i <= end; s += i, i++);
   sp.set_value(s);
}

using clk = std::chrono::steady_clock;

int main() {
   clk::time_point start = clk::now();
   ull beg = 0, end = 1231231231;
   promise<ull> sumPromise;
   future<ull> sumfuture = sumPromise.get_future();
   cout << "Start the process" << endl;
   thread t(sum, move(sumPromise), beg, end);

   cout << "The sum is: " << sumfuture.get() << endl;
   t.join();
   clk::time_point stop = clk::now();
   cout << "total time: " << chrono::duration_cast<chrono::milliseconds> (stop - start).count() << endl;
   return 0;
}