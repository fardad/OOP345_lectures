#include <iostream>
#include "pointers.h"
using namespace std;
typedef int* intptr;

void copyMem( char* des, const char* src, size_t size ) {
   for ( size_t i = 0; i < size; i++ ) {
      des[i] = src[i];
   }
}

int main( ) {
   double a, b = 1234.5678;
   copyMem( reinterpret_cast<char*>( &a ), reinterpret_cast<const char*>( &b ), sizeof( b ) );
   cout << a << endl;
   return 0;
}