#include <iostream>
#include <thread>
#include <future>
using namespace std;



void calculate(promise<int> p) {
   int something = 234;
   p.set_value(something);
}


int main() {
   promise<int> mp;
   future<int> f = mp.get_future();

   thread t(calculate, move(mp));
   t.join();

   cout << "Result: " << f.get() << endl;
   return 0;
}