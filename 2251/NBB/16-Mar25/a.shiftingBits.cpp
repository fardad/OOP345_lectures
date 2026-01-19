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
   int I = 0xA5, J; //   10100101;
                 //  101001010;   14A
   J = I << 1;

   cout << std::uppercase << std::hex << I << " ======= " << std::dec << I << endl;

   cout << std::uppercase << std::hex << J << " ======= " << std::dec << J << endl;
   cout << std::uppercase << std::hex << (I >> 1) << " ======= " << std::dec << (I >> 1) << endl;
   cout << std::uppercase << std::hex << (I >> 8) << " ======= " << std::dec << (I >> 8) << endl;

   return 0;
}