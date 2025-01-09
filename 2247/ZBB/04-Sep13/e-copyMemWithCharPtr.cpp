#include <iostream>
using namespace std;

void copyMem( char* des, const char* src, size_t size ) {
   for ( size_t i = 0; i < size; i++ ) {
      des[i] = src[i];
   }
}
int main( ) {
   double a = 1234.56789;
   double b;
   copyMem( reinterpret_cast<char*>(&b),
      reinterpret_cast<const char*>(&a), sizeof( double ) );
   cout << b << endl;
   return 0;
}