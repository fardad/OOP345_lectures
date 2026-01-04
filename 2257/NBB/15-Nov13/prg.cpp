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
   thread tX = thread(foo, ref(tx), "^^^^^^", 10);
   thread tY = thread(foo, ref(ty), "---------", 5);
   foo(tm, "mmmmmmmm", 6);
   tX.join();
   tY.join();
   cout << endl;
   cout << "Total of chars printed: " << tx + ty + tm << endl;

   return 0;
}
