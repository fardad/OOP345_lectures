#include <iostream>
#include <thread>
using namespace std;
void foo(char sign) {
   for (int i = 0; i < 100; i++) cout << sign;
}
int main() {
   cout << "OOP345 NBB - Mar 23" << endl;
   thread tX(foo, '^');// RAII
   thread tY(foo, 'x');// RAII
   foo('_');
   tX.join();
   tY.join();
   return 0;
}
