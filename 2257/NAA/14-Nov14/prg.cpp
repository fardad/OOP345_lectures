#include <thread>
#include <iostream>
using namespace std;
void foo(int& num, const char* chars, int cnt) {
   for (int i = 0; i < cnt; i++) {
      for (num = 0; chars[num]; num++) {
         cout << chars[num];
      }
   }
   num *= cnt;
}
int main() {
   int tx{}, ty{}, tm{};
   thread tX = thread(foo, ref(tx), "^^^^^^", 5);
   thread tY = thread(foo, ref(ty), "xxxx", 10);
   foo(tm, "----------", 15);
   tX.join();
   tY.join();
   cout << endl;
   cout << "tX printed " << tx << " characters!" << endl;
   cout << "tY printed " << ty << " characters!" << endl;
   cout << "the main thread, priented " << tm << " characters!" << endl;
   cout << "Total of " << tx + ty + tm << " chars printed!" << endl;
   return 0;
}