#include <iostream>
#include <thread>
#include <future>
using namespace std;
typedef unsigned long long ull;
void sum(promise<ull>&& sp,  ull beg, ull end) {
   ull s = 0, i;
   for (i = beg; i <= end; s += i, i++);
   sp.set_value(s);
}

int main() {
   ull beg = 0, end = 1231231231;
   promise<ull> sumPromise;
   future<ull> sumFuture = sumPromise.get_future();
   promise<ull> sumPromise2;
   future<ull> sumFuture2 = sumPromise2.get_future();
   cout << "Start the process!" << endl;
   thread t1(sum, move(sumPromise), beg, end/2);
   thread t2(sum, move(sumPromise2), end/2+1, end);
   cout << "Doing the math!" << endl;
   cout << "The sum is: " << sumFuture.get() + sumFuture2.get() << endl;
   cout << "Done!" << endl;
   t1.join();
   t2.join();
   return 0;
} 