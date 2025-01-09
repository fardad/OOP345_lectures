#include <iostream>
using namespace std;
void foo( double array[] ) {
   cout << "sizeof array in function" << endl;
   cout << sizeof( array ) << endl;
}
int main( ) {
   double d;
   double a[10];
   double b[1000];
   cout << sizeof( int ) << endl;
   cout << sizeof( long long ) << endl;
   cout << sizeof( d ) << endl;
   cout << sizeof( a ) << endl;
   cout << sizeof( a ) / sizeof( double ) << endl;
   foo( b );
   cout << sizeof( double* ) << endl;
   cout << sizeof( int* ) << endl;
   cout << sizeof( char* ) << endl;
   cout << sizeof( long* ) << endl;
   cout << sizeof( float* ) << endl;
   return 0;
}