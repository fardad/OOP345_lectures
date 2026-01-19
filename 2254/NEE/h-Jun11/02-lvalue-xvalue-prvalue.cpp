#include <iostream>
#include <string>
using namespace std;
int main( ) {
   cout << "i-Jun11 OOP345 NEE" << endl;
   cout << string( "abc" ) << endl;
   int a = 10;
   string( "Abc" ) = "whatever";
   for ( int i = 0; i < 10; i++ );


   int x = 5;             // x is an lvalue
   int&& y = 5;           // 5 is a prvalue; y binds an rvalue reference to it
   std::move( x );          // xvalue: we’re telling the compiler we want to move from x
   (x + y);                // prvalue: temporary result of an addition
   std::string( "hi" );      // prvalue: temporary object


   return 0;
}