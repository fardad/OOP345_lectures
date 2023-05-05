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
   thread t(sum, move(sumPromise), beg, end);

   t.join();
   clk::time_point stop = clk::now();
   cout << "total time: " << chrono::duration_cast<chrono::milliseconds> (stop - start).count() << endl;
   cout << "The sum is: " << sumfuture.get() << endl;
   start = clk::now();

   promise<ull> sumPromise1;
   future<ull> sumfuture1 = sumPromise1.get_future();
   promise<ull> sumPromise2;
   future<ull> sumfuture2 = sumPromise2.get_future();
   promise<ull> sumPromise3;
   future<ull> sumfuture3 = sumPromise3.get_future();
   promise<ull> sumPromise4;
   future<ull> sumfuture4 = sumPromise4.get_future();
   cout << "Start the process" << endl;
   thread t1(sum, move(sumPromise1), beg, end/4);
   thread t2(sum, move(sumPromise2), end/4+1, end/4*2);
   thread t3(sum, move(sumPromise3), end/4*2+1, end/4*3);
   thread t4(sum, move(sumPromise4), end/4*3+1, end);

   cout << "The sum is: " << sumfuture1.get() + sumfuture2.get() + sumfuture3.get() + sumfuture4.get() << endl;
   t1.join();
   t2.join();
   t3.join();
   t4.join();
   stop = clk::now();
   cout << "total time: " << chrono::duration_cast<chrono::milliseconds> (stop - start).count() << endl;
   return 0;
}