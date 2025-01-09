#include <iostream>
using namespace std;

void copyMem( void* vdes, const void* vsrc, size_t size ) {
   char* des = reinterpret_cast<char*>(vdes);
   const char* src = reinterpret_cast<const char*>(vsrc);
   for ( size_t i = 0; i < size; i++ ) {
      des[i] = src[i];
   }
}
int main( ) {
   double a = 1234.56789;
   double b;
   copyMem( &b, &a, sizeof( double ) );
   cout << b << endl;
   return 0;
}