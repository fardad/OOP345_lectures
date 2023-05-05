#include <thread>
#include <iostream>
using namespace std;
void foo(int& num, const char* chars) {
   for (int i = 0; i < 10; i++) {
      for (num = 0; chars[num]; num++) {
         cout << chars[num];
      }
   }
   num *= 10;
}
int main() {
   int tx, ty, tm;
   std::thread tX = std::thread(foo,std::ref(tx), "^^^^^^");
   std::thread tY = std::thread(foo,std::ref(ty), "------------");
   foo(tm,"________________________");
   tX.join();
   tY.join();
   cout << endl;
   cout << "tX printed " << tx << " characters!" << endl;
   cout << "tY printed " << ty << " characters!" << endl;
   cout << "the main thread, priented " << tm << " characters!" << endl;
   return 0;
}
