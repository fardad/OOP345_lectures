#include <iostream>
using namespace std;
struct Container {
   int value;
   bool hasMore( const Container& C ) {
      return value > C.value;
   }
};


//template <typename T>
template <class T>
T largest( T a, T b ) {
   return a > b ? a : b;
}

template <>
Container largest<Container>( Container C1, Container C2 ) {
   return C1.hasMore( C2 ) ? C1 : C2;
}


template <>
const char* largest<const char*>( const char* a, const char* b ) {
   return strcmp( a, b ) > 0 ? a : b;
}

int main( ) {

   double a = 2.3;
   int b = 4;
   cout << largest<double>( a, b );
   return 0;
}