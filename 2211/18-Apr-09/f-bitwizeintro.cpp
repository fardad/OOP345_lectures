#include <iostream>
using namespace std;

void bits(unsigned char ch) {
   unsigned char mask = 1; // 0000 0001
   mask <<= (sizeof(unsigned char) * 8 - 1);
   for (int i = 0; i < sizeof(unsigned char) * 8; i++) {
      // cout << (ch & mask) ? 1 : 0;
      cout << bool(ch & mask);
      mask >>= 1;
   }
   cout << endl;
}

void bits(void* mem, unsigned int size) {

}


int main() {
   char ch = 'A';
   cout << (int)ch << endl;
   cout << !ch << endl;
   bits(ch);
   ch = ~ch;  // bitwise not
   bits(ch);

   int a = 123;
   int b = ~a + 1;

   cout << b << endl;
   

   return 0;
}

/*
  1000 0000
  0100 0000
  0010 0000

   0100 0001  = 65
&  001000000
   =========
   000000000
ch:
 0100 0001
~0100 0001 = 1011 1110

0100 0001
1010 1010

  0100 0001
& 1010 1001
  =========
  0000 0001

  0100 0001
| 1010 1001
  =========
  1110 1001

  0100 0001
^ 1010 1001
  =========
  1110 1000



  1010 1001 << 1 = 0101 0010

  1010 1001 >> 1 = 0101 0100





*/