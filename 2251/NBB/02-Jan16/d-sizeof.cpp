#include <iostream>
using namespace std;
struct test {
   long b;
   char c;
   long i;
   double d;
};
struct test2 {
   double d;
   long b;
   long i;
   char c;
};
int main( ) {
   long double d;
   cout << sizeof( int ) << endl;
   cout << sizeof( long long ) << endl;
   cout << sizeof( d ) << endl;
   cout << "long: " << sizeof( long ) << endl;
   cout << "char: " << sizeof( char ) << endl;
   cout << "long: " << sizeof( long ) << endl;
   cout << "double: " << sizeof( double ) << endl;
   cout << sizeof( test ) << endl;
   cout << sizeof( test2 ) << endl;

   return 0;
}