#include <iostream>
#include <fstream>
using namespace std;
int main() {
   char c1 = 0x13;  // 00010011
   char c2 = 0x16;  // 00010110
                    // 00000001
                    //&00000001
                    // 00000010 

   int bitIndex0C1 = c1 & 1;
   int bitIndex0C2 = c2 & 1;

   int bitIndex1C1 = c1 & 2;
   int bitIndex1C2 = c2 & 2;

   int bitIndex2C1 = c1 & 4;
   int bitIndex2C2 = c2 & 4;


   cout << bitIndex0C1 << endl;
   cout << bitIndex0C2 << endl;
   cout << endl;
   cout << bitIndex1C1 << endl;
   cout << bitIndex1C2 << endl;
   cout << endl;
   cout << bitIndex2C1 << endl;
   cout << bitIndex2C2 << endl;

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