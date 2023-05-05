#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
void add(unsigned long& value, mutex& key) {
   for (size_t i = 0; i < 100; i++) {
      key.lock();
      value++;  // going to the washroom
      key.unlock();
   }
}
int main() {
   unsigned long value;
   int num = 1000;
   mutex theKey;
   for (int i = 0; i < num; i++) {
      value = 0;
      vector<thread> adds;
      for (int i = 0; i < 100; i++) {
         adds.push_back(thread(add, ref(value), ref(theKey)));
      }
      for (thread& a : adds) {
         a.join();
      }
      cout << value << " ";
   }
   cout << endl;
   return 0;
}