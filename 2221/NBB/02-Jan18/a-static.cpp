#include <iostream>
using namespace std;

void foo() {
   static int a = 5;
   a++;
   cout << a << endl;
}


int main() {
   for (int i = 0; i < 10; i++) {
      foo();
   }
   return 0;
}