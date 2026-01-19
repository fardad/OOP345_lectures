#include <iostream>
using namespace std;
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
void bits(int val) {
   unsigned int m = 1 << (sizeof(int) * 8 - 1);
   int cnt = 1;
   while (m) {
      cout << !!(m & val);
      m >>= 1;
      if (cnt++ == 8) {
         cout << " ";
         cnt = 1;
      }
   }
   cout << endl;
}


struct Status {
   unsigned int value : 8;
   unsigned int filler : 8;
   unsigned int visible : 1;
   unsigned int color : 4;
};

union intStat {
   Status S;
   unsigned int value;
};

int main() {
   intStat is;
   is.value = 0;
   is.S.visible = 1;
   is.S.color = 0xF;
   is.S.value = 0xFF;
   bits(is.value);
   

   return 0; 
}