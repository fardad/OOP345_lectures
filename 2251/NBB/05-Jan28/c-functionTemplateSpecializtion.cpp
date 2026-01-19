#include <iostream>
#include <cstring>
using namespace std;

struct Container {
   int value;
   bool hasMore( const Container& );
};


template <typename T>
T largest( T a, T b ) {
   return a > b ? a : b;
}

template <>
Container largest<Container>( Container a, Container b ) {
   return a.hasMore(b) ? a : b;
}

template <>
const char* largest<const char*>( const char* a, const char* b ) {
   return strcmp( a, b ) > 0 ? a : b;
}



int main(){
   cout << "OOP345 NBB - Jan 28 " << endl;
   double l = largest( 2.3, 50.5 );
   Container A, B, C;
   C = largest( B, C );
   return 0;
}