#include <iostream>
using namespace std;
void sum( int a, int b ) {
   cout << "Sum is " << (a + b) << endl;
}
void prod( int a, int b ) {
   cout << "Product is " << (a * b) << endl;
}
int main( ) {
   void (*func)(int, int) = nullptr;
   func = sum;
   func( 10, 20 );  // sum will be called
   func = prod;
   func(20, 30);   // proc will be called
   return 0;
}
