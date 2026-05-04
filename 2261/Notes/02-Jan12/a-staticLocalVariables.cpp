#include <iostream>
using namespace std;
void foo() {
   static int a = 10;
   a++;
   cout << a << endl;
}


int main() {
   cout << "OOP345 JAN12" << endl;
   for (int i = 0; i < 5; i++) {
      foo();
   }
   return 0;
}