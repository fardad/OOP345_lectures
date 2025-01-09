#include <iostream>
using namespace std;
void sum( int a, int b ) {
   cout << "Sum is " << (a + b) << endl;
}
void prod( int a, int b ) {
   cout << "Product is " << (a * b) << endl;
}
void divid( int a, int b ) {
   cout << "divid is " << (a / b) << endl;
}
void reduce( int a, int b ) {
   cout << "reduce is " << (a - b) << endl;
}


int main( ) {
   void ( *funcs[4] )( int, int ) = { sum, prod, divid, reduce };
   for ( int i = 0; i < 4; i++ ) {
      funcs[i]( 10, 20 );
   }
   return 0;
}
