#include <thread>
#include <iostream>
using namespace std;
void foo(char sign) {
   for(int i = 0; i < 100; i++) {
      cout << sign;
   }
}
int main() {
   std::thread tX = std::thread(foo, '*');
   std::thread tY = std::thread(foo, '+');
   foo('-');
   tX.join();
   tY.join();
   return 0;
}