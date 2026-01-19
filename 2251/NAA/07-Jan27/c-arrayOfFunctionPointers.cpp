#include <iostream>
using namespace std;
void sum( int a, int b ) {
   cout << (a + b) << endl;
}
void prod( int a, int b ) {
   cout << (a * b) << endl;
}
void repeat( int a, int num ) {
   for ( int i = 0; i < num; cout << a << " ", i++ );
   cout << endl;
}
int main( ) {
   cout << "address of sum in memory: " << reinterpret_cast<unsigned long long>(sum) << endl;
   cout << "address of prod in memory: " << reinterpret_cast<unsigned long long>(prod) << endl;

   void (*funcPtr[3])(int, int) { sum, prod, repeat };
   for ( int i = 0; i < 3; i++ ) {
      funcPtr[i]( 10, 20 );
   }
   return 0;
}
