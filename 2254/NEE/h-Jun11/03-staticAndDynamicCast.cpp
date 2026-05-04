#include <iostream>
#include <string>
using namespace std;
int main( ) {
   cout << "i-Jun11 OOP345 NEE" << endl;
   double d = 3.14;
   int i = static_cast<int>(d); // truncates the decimal part
/*
   Base* b = new Derived1( );
   Derived1* d = dynamic_cast<Derived1*>(b); // if not possible, returns null
   if ( d ) {
      // Safe to use d
   }
   Base* b = new Derived2( );
   Derived1* d = dynamic_cast<Derived1*>(b); // if not possible, returns null
   if ( d ) { // d wil be null
      // Safe to use d
   }

*/

   return 0;
}