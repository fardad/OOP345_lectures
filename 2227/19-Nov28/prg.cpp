#include <iostream>
using namespace std;
/*    
0100 0001
0000 0001 &
---------
0000 0001  // non zero

0100 0001
0000 0010 &  <---
---------
0000 0000  // zero

0100 0001
0100 0000 &  <---
---------
0100 0000  // non zero


*/
ostream& bits(char ch) {
   unsigned char mask = 1; // 0000 0001
   mask = mask << (sizeof(mask) * 8-1);
                           // 1000 0000
   for(int i = 0; i < sizeof(unsigned char) * 8; i++) {
      cout << bool(ch & mask);
      // shift mask one to left
      mask = mask >> 1;
   }
   return cout;
}


int main() {
   char ch = 20;
   bits(ch) << endl;
   cout << int(ch) << endl;
   ch = ~ch + 1;
   bits(ch) << endl;
   cout << int(ch) << endl;
   bits(ch) << endl;
   ch = ch << 1;
   bits(ch) << endl;
   ch = 20;
   cout << "---------------" << endl;
   bits(ch) << endl;
   ch >>= 1; // ch = ch >> 1;
   bits(ch) << endl;
   ch = -20;
   cout << "---------------" << endl;
   bits(ch) << endl;
   ch >>= 1; // ch = ch >> 1;
   bits(ch) << endl;



   return 0;
}

/*
* 
 



   010 0100 1001
   x249
   0100 0001  = 0x41
   0010 0000 |    <- mask
  -----------
   0110 0001 
0000   0
0001   1
0010   2
0011   3
0100   4
0101   5
0110   6
0111   7
1000   8
1001   9
1010   A
1011   B
1100   C
1101   D
1110   E
1111   F



*/