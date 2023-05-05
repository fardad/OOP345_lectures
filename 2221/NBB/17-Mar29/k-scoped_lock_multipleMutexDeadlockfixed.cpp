#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex key1;
mutex key2;
// deadlock since foo1 waits for lock2 to unlock and foo2 waits for key1 to unlock forever.
void foo1(int& value) {
   scoped_lock sl(key1, key2);
   value++;
   ///
}


void foo2(int& value) {
   scoped_lock(key1, key2);
   value++;
   ///
}