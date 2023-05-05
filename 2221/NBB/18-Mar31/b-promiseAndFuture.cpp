#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;
void foo(promise<int>& fp) {
   fp.set_value(10);
   this_thread::sleep_for(chrono::seconds(5));
   cout << "Thread is done!" << endl;
}


int main() {
   promise<int> p;

   future<int> f = p.get_future();
   cout << "Before thread..." << endl;

   thread t(foo, ref(p));

   cout << "In Host: " <<  f.get() << endl;
   t.join();
   return 0;
}