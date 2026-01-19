#include <iostream>
using namespace std;

void prnA( int a[] ) {
   cout << "in prnA" << endl;
   cout << sizeof( a ) << endl;
}
int main( ) {
   int i;
   int a[10];
   cout << sizeof( i ) << "   " << sizeof( int ) << endl;
   cout << sizeof( a ) << endl;
   prnA(a );
   return 0; 
}