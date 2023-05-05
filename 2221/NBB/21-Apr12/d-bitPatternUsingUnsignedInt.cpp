#include <iostream>
#include <fstream>
using namespace std;

void bitPattern(unsigned int v) {
   unsigned int mask = 1u << ((sizeof(v) * 8) - 1);                        
   for (int i = 1; i <= (sizeof(v) * 8); i++) {
      if (v & mask) {
         cout << "1";
      }
      else {
         cout << "0";
      }
      mask = mask >> 1;
   }
   cout << endl;
}

int main() {
   char c1 = 0x16;  // 00010110
   bitPattern(c1);
   return 0;
}
