#include <iostream>
#include <fstream>
using namespace std;
int main() {
   char c1 = 0x12; //    00010010
   char c2 = 0x43; //    01000011
   char c3;        //&   00000010  
                   //|   01010011   0x53  (dec 83)
                   //^   01010001     
                   //~c1 11101101
   c3 = c1 & c2;      // both true to be true
   
   cout << int(c3) << endl;
   c3 = c1 | c2;      // at lease one true to be true

   cout << int(c3) << endl;

   c3 = c1 ^ c2;      // different to be true


   cout << "c1:       " << int(c1) << endl;
   cout << "c2:       " << int(c2) << endl;
   cout << "c3=c1^c2: " << int(c3) << endl;
   cout << "c3 ^ c1   " << int(c3 ^ c1) << endl;
   cout << "c3 ^ c2   " << int(c3 ^ c2) << endl;

   // enc = data ^ key;


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