#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex key1;
mutex key2;
// deadlock since foo1 waits for lock2 to unlock and foo2 waits for key1 to unlock forever.
void foo1(int& value) {
   key1.lock();
   key2.lock();
   value++;
   ///
}


void foo2(int& value) {
   key2.lock();
   key1.lock();
   value++;
   ///
}