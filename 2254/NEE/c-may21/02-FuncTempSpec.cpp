#include <iostream>
using namespace std;

struct Container {
   int value;
   bool hasMore( const Container& C) {
      return value > C.value;
   }
};


//template <typename T>
template <class T>
T largest( T a, T b ) {
   return a > b ? a : b;
}

template <>
Container largest<Container>( Container c1, Container c2 ) {
   return c1.hasMore( c2 ) ? c1 : c2;
}

template <>
const char* largest<const char*>( const char* a, const char* b ) {
   return strcmp( a, b ) > 0 ? a : b;
}

int main( ) {
   cout << "OOP345NEE May21" << endl;
   int a = 10;
   int b = 20;
   int c;
   c = largest( a, b );
   cout << c << endl;
   return 0;
}