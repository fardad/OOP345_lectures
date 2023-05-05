#include <iostream>
using namespace std; 

void add(int a, int b) {
   cout << a << "+" << b << "=" << (a + b) << endl;
}
void sub(int a, int b) {
   cout << a << "-" << b << "=" << (a - b) << endl;
}
void mul(int a, int b) {
   cout << a << "x" << b << "=" << (a * b) << endl;

}
void divid(int a, int b) {
   cout << a << "/" << b << "=" << (a / b) << endl;
}
void line(int len, int ch) {
   for (int i = 0; i < len; i++) {
      cout << char(ch);
   }
   cout << endl;
}

auto main()->int {
   // fptr is a pointer to any function 
   // returning void receiving two ints.
   void (*fptr[5])(int, int) = { add, sub, mul, divid, line };

   for (int i = 0; i < 5; i++) {
      fptr[i](79, 45);
   }

   return 0;
}

