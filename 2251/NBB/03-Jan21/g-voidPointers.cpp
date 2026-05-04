#include <iostream>
using namespace std;

void copyMem( void* des, const void* src, size_t size ) {
   char* d = reinterpret_cast<char*>(des);
   const char* s = reinterpret_cast<const char*>(src);
   for ( size_t i = 0; i < size; i++ ) {
      d[i] = s[i];
   }
}
int main( ) {
   double a = 1234.56789;
   double b;
   copyMem( &b, &a, sizeof( double ) );
   cout.setf( ios::fixed );
   cout << b << endl;
   return 0;
}