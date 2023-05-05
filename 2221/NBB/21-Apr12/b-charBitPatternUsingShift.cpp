#include <iostream>
#include <fstream>
using namespace std;
// unsigned char n;
// n = 1  0000 0001
// n = n << 1 0000 0010    n = n * 2;   n = n << 1;
// n = n << 1 0000 0100
// n = n << 1 0000 1000
// n = n << 1 0001 0000
// n <<= 1 0010 0000
// n <<= 1 0100 0000
// n <<= 1 1000 0000
// n <<= 1 0000 0000  // gone to barbage
// n = 0x80   1000 0000
// n >>= 1     0100 0000
// n >>= 1     0010 0000
// n >>= 1     0001 0000
// n >>= 1     0000 1000
// n >>= 1     0000 0100
// n /= 2      0000 0010
// n >>= 1     0000 0001
// n >>= 1     0000 0000 // gone to garbage

void bitPattern(char ch) {
   int mask = 0x80;
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

int main() {
   char c1 = 0x16;  // 00010110
   bitPattern(c1);
   return 0;
}
