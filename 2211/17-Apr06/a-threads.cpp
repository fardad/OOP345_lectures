#include <thread>
#include <iostream>
using namespace std;
void foo(char sign) {
   for(int i=0;i<100;i++) {
      cout << sign;
   }
}
void threads() {
   std::thread tX = std::thread(foo, '^');
   std::thread tY = std::thread(foo, '-');
   foo('_');
   tX.join();
   tY.join();
}
int main() {
   threads();
   cout << endl << endl;
   threads();
   cout << endl << endl;
   threads();
   cout << endl << endl;

   return 0;
}