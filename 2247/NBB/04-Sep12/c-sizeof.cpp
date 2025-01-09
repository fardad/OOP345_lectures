#include <iostream>
using namespace std;
void  foo( double a[] ) {
   cout << sizeof( a ) << endl;
}
int main( ) {
   double d[10];
   cout << sizeof( d ) << endl;
   foo( d );
   return 0;
}