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

int main( ) {
   int I = 0x7C,  // 01111100
       J = 0x95;  // 10010101
   int K = J & I; // 00010100   0x14
       
   cout << std::uppercase << std::hex << K << " ======= " << std::dec << K << endl;
   K = J | I;     // 11111101   0xFD
   cout << std::uppercase << std::hex << K << " ======= " << std::dec << K << endl;
   K = J ^ I;     // 11101001   0xE9
   cout << std::uppercase << std::hex << K << " ======= " << std::dec << K << endl;
   return 0;
}