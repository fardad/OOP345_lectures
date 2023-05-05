#include <iostream>
#include <fstream>
using namespace std;
void bitPattern(char ch) {
   unsigned int mask = 0x80;
   for (int i = 1; i <= 8; i++) {
      if (ch & mask) {
         cout << "1";
      }
      else {
         cout << "0";
      }
      mask = mask >> 1;
   }
   cout << endl;
}
//
// singed char -128 -> +127
// unsigned char  0 -> 255
int main() {
   char c1 = 1;
   unsigned char uc1 = 0x85;
   bitPattern(c1);
   c1 <<= 4;
   bitPattern(c1);
   c1 = 0x85;
   bitPattern(c1);
   c1 >>= 4;
   bitPattern(c1);
   bitPattern(uc1);
   uc1 >>= 4;
   bitPattern(uc1);
   c1 = 95;
   bitPattern(c1);
   c1 = ~c1 + 1;
   bitPattern(c1);
   cout << int(c1) << endl;

   return 0;
}

