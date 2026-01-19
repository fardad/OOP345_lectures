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
}

int main( ) {
   cout << "OOP345NEE - May26 - Functions" << endl;
   cout << reinterpret_cast<long long>(prod) << endl;
   cout << reinterpret_cast<long long>( sum ) << endl;
   cout << reinterpret_cast<long long>( prn ) << endl;

   void (*fptr)(int, int) = nullptr;
   fptr = sum;
   fptr( 10, 20 );
   fptr = prn;
   fptr( 10, 20 );
   return 0;
}