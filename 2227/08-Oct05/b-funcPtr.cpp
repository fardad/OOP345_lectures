#include <iostream>
#include <string>
using namespace std;
void sum(int a, int b) {
   cout << (a + b) << endl;
}
void prod(int a, int b) {
   cout << (a * b) << endl;
}

int main() {
   int x = 10;
   int y = 5;

   void (* funcptr)(int, int);

   sum(x, y);
   prod(x, y);
   /*cout << unsigned(sum) << endl;
   cout << unsigned(prod) << endl;*/
   funcptr = sum;

   funcptr(10, 20);
   funcptr = prod;

   funcptr(500, 5);

   return 0;
}