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
   int X;
   auto myFunc = add;

   myFunc(10, 20);
   myFunc = line;
   myFunc(30, '-');

   return 0;
}

