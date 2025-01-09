#include <iostream>
using namespace std;
void sum( int a, int b ) {
   cout << "Sum is " << (a + b) << endl;
}
void prod( int a, int b ) {
   cout << "Product is " << (a * b) << endl;
}

// bool myFunc( iostream& whatever, int* ptr, double& x, const char* str, string S );

int main( ) {
  // bool (*funcptr)( iostream & , int* , double& , const char* , string );



   void (*func)( int, int ) = nullptr;
   func = sum;
   func( 10, 20 ); // C++ syntax of calling a function using its address
   func = prod;
   (*func)( 20, 30 ); // C syntax of calling a function using its address


   //cout << "Sum address in memory: " << reinterpret_cast<unsigned long long>(sum) << endl;
   //cout << "Prod address in memory: " << reinterpret_cast<unsigned long long>(prod) << endl;
   //sum( 10, 20 );
   return 0;
}
