#include <iostream>
#include <fstream>
using namespace std;
int main() {
   char c1 = 0x12;// dec 18 //   00010010
   char c3;

   c3 = ~c1;

   cout << int(c3) << endl;

   int a = 1234;
   int b;


   b = ~a + 1; // 2 complement

   cout << b << endl;
   
   /*
   a = b -c;
   a = b + (~c+1);
   
   */

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