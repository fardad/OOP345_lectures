#include <iostream>
using namespace std;
void sum( int a, int b ) {
   cout << "Sum is " << (a + b) << endl;
}
void prod( int a, int b ) {
   cout << "Product is " << (a * b) << endl;
}
int main( ) {
   void (*func)( int, int ) = nullptr;
   func = sum;
   func( 10, 20 );
   func = prod;
   func( 20, 30 );


   //cout << "Sum address in memory: " << reinterpret_cast<unsigned long long>(sum) << endl;
   //cout << "Prod address in memory: " << reinterpret_cast<unsigned long long>(prod) << endl;
   //sum( 10, 20 );
   return 0;
}
