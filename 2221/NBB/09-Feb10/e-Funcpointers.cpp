#include <iostream>
using namespace std; 

void add(int a, int b) {
   cout << a << "+" << b << "=" << (a + b) << endl;
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
   void (*fptr)(int, int) = nullptr;
   
   ftpr = add;
   fptr(10, 20);
   fptr = line;
   fptr(40, '-');

   return 0;
}

