#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T maximum( T a, T b ) {
   return a > b ? a : b;
}
template<>
const char* maximum<const char*>( const char* a, const char* b ) {
   return strcmp( a, b ) > 0 ? a : b;
}

int main( ) {
   int a = 10;
   double b = 10.2;
   double dres;
   double ires;

   ires  =  maximum<int>( a, b );
   dres = maximum<double>( a, b );


   return 0;
}