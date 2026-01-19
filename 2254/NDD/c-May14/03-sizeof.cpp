#include <iostream>
using namespace std;
void foo( char name[] ) {
   cout << sizeof( name ) << endl;
   cout << sizeof( char* ) << endl;

}
void foo( double d[] ) {
   cout << sizeof( d ) << endl;
   cout << sizeof( double* ) << endl;
}
int main( ) {
   char name[] = "Fardad";
   double d[10];
   cout << sizeof( name ) << endl;
   cout << sizeof( d ) << endl;
   foo(name );
   foo( d );
   return 0;
}