#include <iostream>
#include <fstream>
using namespace std;

void bitPattern(char ch) {
   int n = 1;
   for (int i = 1; i < 8; i++) {
      if (ch & n) {
         cout << "1";
      }
      else {
         cout << "0";
      }
      n = n * 2;
   }
   cout << endl;
}

int main() {
   char c1 = 0x13;  // 00010011
   char c2 = 0x16;  // 00010110
                    // 00000001
                    //&00000001
                    // 00000010 
   bitPattern(c2);

   return 0;
}
/*
0000  0
0001  1
0010  2
0011  3
0100  4
0101  5
0110  6
0111  7
1000  8
1001  9
1010  A
1011  B
1100  C
1101  D
1110  E
1111  F

*/
