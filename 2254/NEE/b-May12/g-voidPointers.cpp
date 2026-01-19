#include <iostream>
#include "pointers.h"
using namespace std;
typedef int* intptr;

void copyMem( void* des, const void* src, size_t size ) {
   for ( size_t i = 0; i < size; i++ ) {
      reinterpret_cast<char*>(des)[i] = reinterpret_cast<const char*>(src)[i];
   }
}

int main( ) {
   double a, b = 1234.5678;
   int i[5], j[5]{ 1, 2, 3, 4,5 };
   copyMem(  &a,&b,  sizeof( b ) );
   copyMem( i, j, sizeof( int ) * 5 );
   cout << a << endl;
   for ( int n = 0; n < 5; cout << i[n++] << " " );
   cout << endl;
   return 0;
}