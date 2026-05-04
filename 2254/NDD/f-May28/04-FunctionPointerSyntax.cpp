#include <iostream>
using namespace std;
void sum( int a, int b ) {
   cout << (a + b) << endl;
}
void prod( int a, int b ) {
   cout << (a * b) << endl;
}
void prn( int num, int cnt ) {
   for ( int i = 0; i < cnt; i++, cout << num << " " );
   cout << endl;
}
int main( ) {
   void (*farr[3])(int, int) = { sum , prod, prn };
   void (*fptr)( int, int );
   fptr = sum;

   fptr( 10, 40 );

   fptr = prod;

   fptr( 10, 40 );

   fptr = prn;

   fptr( 10, 40 );
   cout << "*********************" << endl;
   for ( int i = 0; i < 3; i++ ) {
      farr[i]( 50, 10 );
   }
   cout << "*********************" << endl;
   return 0;
}