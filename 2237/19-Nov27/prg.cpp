#include <iostream>
using namespace std;

void bitPattern(const char* prompt, unsigned char ch) {
   unsigned char m = 0x80;
   cout << prompt;
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
   unsigned char v = 0x6D;
   unsigned char k = 0x37;
   unsigned char e = 0;
   unsigned char r = 0;
   bitPattern("v 0x6D: ", v);
   bitPattern("k 0x37: ", k);
   e = v & k;
   bitPattern("e= v&k: ", e);
   cout << "===========================" << endl;
   bitPattern("v 0x6D: ", v);
   bitPattern("k 0x37: ", k);
   e = v | k;
   bitPattern("e= v|k: ", e);
   cout << "===========================" << endl;
   bitPattern("v 0x6D: ", v);
   bitPattern("k 0x37: ", k);
   e = v ^ k;
   bitPattern("e= v^k: ", e);
   cout << "===========================" << endl;
   bitPattern("e 0x??: ", e);
   bitPattern("k 0x37: ", k);
   r = e ^ k;
   bitPattern("r= e^k: ", r);
   return 0;
}

