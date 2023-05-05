#include <iostream>
#include <thread>
#include <vector>
using namespace std;
void add(unsigned long& value) {
   for (size_t i = 0; i < 100; i++) {
      value++;
   }
}

int main() {
   unsigned long value;
   int num = 1000;
   for (int i = 0; i < num; i++) {
      value = 0;
      vector<thread> adds;
      for (int i = 0; i < 100; i++) {
         adds.push_back(thread(add, ref(value)));
      }
      for (thread& a : adds) {
         a.join();
      }
      cout << value << " ";
   }
   cout << endl;
   return 0;
}