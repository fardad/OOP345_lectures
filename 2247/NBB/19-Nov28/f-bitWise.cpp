#include <iostream>
using namespace std;
// unsigned char n;
// n = 1  0000 0001
// n *= 2 0000 0010
// n *= 2 0000 0100
// n *= 2 0000 1000
// n *= 2 0001 0000
// n *= 2 0010 0000
// n *= 2 0100 0000
// n *= 2 1000 0000
// n *= 2 0000 0000  // gone to barbage
// n = 0x80   1000 0000
// n /= 2     0100 0000
// n /= 2     0010 0000
// n /= 2     0001 0000
// n /= 2     0000 1000
// n /= 2     0000 0100
// n /= 2     0000 0010
// n /= 2     0000 0001
// n /= 2     0000 0000 // gone to garbage

void bitPattern( unsigned int v ) {
   unsigned int m = 1;
   m = m << (sizeof( int ) * 8 - 1);
   for ( int i = 0; i < sizeof( int ) * 8; i++ ) {
      if ( v & m ) {
         cout << 1;
      }
      else {
         cout << 0;
      }
      m = m >> 1; // this ins not cin!!!!! this is right shifting bits in ch
   }
   cout << endl;

}

void bitPattern( unsigned char ch ) {
   unsigned char m = 0x80;
   for ( int i = 0; i < 8; i++ ) {
      if ( ch & m ) {
         cout << 1;
      }
      else {
         cout << 0;
      }
      m = m >> 1; // this ins not cin!!!!! this is right shifting bits in ch
   }
   cout << endl;
}

int main( ) {
   unsigned char v = 0xAC;
   unsigned char w = 0x34;
   unsigned int i = 12345678;
   bitPattern( i );
   bitPattern( v );
   v = v << 2;
   bitPattern( v );
   return 0;
}