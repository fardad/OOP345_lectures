#include <thread>
#include <iostream>
#include <future>
using namespace std;
typedef unsigned long long ull;
void sum(promise<ull>&& sp, ull beg, ull end) {
   ull s{}, i;
   for (i = beg; i <= end; s += i,i++);
   sp.set_value(s);
}

int main() {
   ull beg = 0, end = 1231231231;
   promise<ull> sumPromise;
   future<ull> sumFuture = sumPromise.get_future();
   promise<ull> sumPromise1;
   future<ull> sumFuture1 = sumPromise1.get_future();
   promise<ull> sumPromise2;
   future<ull> sumFuture2 = sumPromise2.get_future();
   cout << "Start the process" << endl;
   thread t1(sum, move(sumPromise), beg, end/3);
   thread t2(sum, move(sumPromise1), end/3+1, end/3*2);
   thread t3(sum, move(sumPromise2), end / 3 * 2 + 1, end);
   cout << "Doing the math..." << endl;
   cout << "The sum is " << sumFuture.get() + sumFuture1.get() + sumFuture2.get() << endl;
   t1.join();
   t2.join();
   t3.join();
   return 0;
}

