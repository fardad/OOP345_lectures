#include <iostream>
using namespace std;
//template <typename T>


struct Container {
   int value;
   bool hasMore( const Container& C ) {
      return value > C.value;
   }
};
template <typename T>
T largest( T a, T b ) {
   return a > b ? a : b;
}

template<>
const char* largest<const char*>( const char* a, const char* b ) {
   return strcmp( a, b ) > 0 ? a : b;
}

template <>
Container largest<Container>( Container C1, Container C2 ) {
   return C1.hasMore( C2 ) ? C1 : C2;
}


int main( ) {
   int i = 10;
   int j = 20;
   double d = 40;
   int k;
   char str1[] = "Fred";
   char str2[] = "jack";
   char* l;
   k = largest( i, j );
   //  l = largest( str1, str2 );
   k = largest<int>( j, d );
   return 0;
}