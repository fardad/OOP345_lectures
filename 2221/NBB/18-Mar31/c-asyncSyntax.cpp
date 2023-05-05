#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

int asyncPlus10(int value) {
   cout << "asyncPlus10 id: " << this_thread::get_id() << endl;
   cout << "returing 10 Plus " << value << endl;
   return 10 + value;
}


int main() {
   cout << "Main thread id: " << this_thread::get_id() << endl;
   future<int> fret = async(asyncPlus10, 20);
//   future<int> fret = async(launch::deferred, asyncPlus10, 20);
//   future<int> fret = async(launch::async, asyncPlus10, 20);
   cout << fret.get() << endl;
   cout << "do something in main after" << endl;

   return 0;
}