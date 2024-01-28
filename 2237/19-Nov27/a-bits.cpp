#include <iostream>
using namespace std;
/*
*/



//   Do this for pratice.
//    cout << bits << v << endl;

void bitPattern( unsigned int v ) {
   unsigned int m = 1;
   m = m << (sizeof( int ) * 8 - 1);
   for ( int i = 0; i < sizeof(int)*8; i++ ) {
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

void bitPattern(unsigned char ch) {
   unsigned char m = 0x80;
   for (int i = 0; i < 8; i++) {
      if (ch & m) {
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
   char x = 1;
   x <<= 7;
   cout << int(x) << endl;
   int a, b = 10, c = 4;
   char w = 0x34;
   char m;
   bitPattern(unsigned char(w));
   cout << int(w) << endl;
   m = ~w;
   bitPattern(unsigned char(m));
   m = m + 1;
   bitPattern(unsigned char(m));
   cout << int(m) << endl;
   cout << " " << int(w) << ": "; bitPattern(unsigned char(w));
   cout << int(m) << ": "; bitPattern(unsigned char(m));
   a = b - c;
   cout << a << endl;
   a = b + (~c + 1);
   cout << a << endl;
   m = 127;
   cout << "7F "; bitPattern(unsigned char(m));
   m = -128;
   cout << "80 "; bitPattern(unsigned char(m));

   return 0;
}
/*  111111  
 52: 00110100
-52: 11001100+
     00000000

     00000001   -> 127
     11111111   -> -128


     11001100
     11100110

     // left shift always fills the right with zero
     // right shift fills the left with zero if the variable is an unsiged
     // right shift fills the left with one if the variable is a signed one


*/