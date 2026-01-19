/*
  0  0000
  1  0001
  2  0010
  3  0011
  4  0100
  5  0101
  6  0110
  7  0111
  8  1000
  9  1001
A 10 1010
B 11 1011
C 12 1100
D 13 1101
E 14 1110
F 15 1111
*/

#include <iostream>
using namespace std;

void bitPattern( unsigned int v ) {
   unsigned int m = 1 << (sizeof(unsigned int)*8-1);
   int cnt = 1;
   while ( m ) {
      cout << !!(m & v);
      m >>= 1;
      if ( cnt++ == 8 ) {
         cout << " ";
         cnt = 1;
      }
   }
   cout << endl;
}


int main( ) {
   int C = 0xA2, B;

   cout << std::uppercase << std::hex << C << "=====" << std::dec << C << endl;
   bitPattern( C );

   B = C << 1;

   cout << std::uppercase << std::hex << B  << "=====" << std::dec << B  << endl;
   bitPattern( B );

   B = C >> 1;

   cout << std::uppercase << std::hex << B << "=====" << std::dec << B << endl;
   bitPattern( B );

   B = 0x2;

   cout << std::uppercase << std::hex << B << "=====" << std::dec << B << endl;
   bitPattern( B );

   B = -B;

   bitPattern( B );

   return 0;
}














