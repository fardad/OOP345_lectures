#include <iostream>
using namespace std;

#include <iostream>

int getValue( ) {
   return 42; // Returns an rvalue
}


int main( ) {
   int x = 5;       // 'x' is an lvalue; '5' is an rvalue
   int y = x;       // 'x' is an lvalue; its value is used as an rvalue
   int z = x + y;   // 'x + y' is an rvalue

   int* p = &x;     // '&x' is valid; 'x' is an lvalue

   // Invalid: cannot assign to an rvalue
   // 10 = x;       // Error: lvalue required as left operand of assignment

   // Invalid: cannot take the address of an rvalue
   // int* q = &10; // Error: cannot take the address of an rvalue

   std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
   return 0;
}