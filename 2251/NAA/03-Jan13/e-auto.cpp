#include <iostream>
using namespace std;
double foo( ) {
   return 123.456;
}

int main() {
   auto i = 0; // i is int
   short s = 10;
   auto a = s;   // a is short
   auto k = 10u; // k is an unsigned int;
   auto d = foo( ); // d is double
 
   return 0;
}