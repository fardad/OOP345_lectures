#include <iostream>
using namespace std;
void sum( int a, int b ) {
   cout << (a + b) << endl;
}
void prod( int a, int b ) {
   cout << (a * b) << endl;
}
void repeat( int val, int num ) {
   for ( int i = 0; i < num; i++, cout << val << " " );
   cout << endl;
}
int main( ) {
   sum( 10, 30 );
   prod( 10, 30 );
   cout << reinterpret_cast<unsigned long long>(sum) << endl;
   cout << reinterpret_cast<unsigned long long>(prod) << endl;

   void (*fptr)( int, int );
   fptr = sum;
   fptr( 40, 10 );
   fptr = prod;
   fptr( 40, 10 );
   fptr = repeat;
   fptr( 40, 10 );

   void (*fp[3])(int, int) { sum, prod, repeat };
   for ( int i = 0; i < 3; i++ ) {
      fp[i]( 20, 3 );
   }


   return 0;

}