#include <iostream>
#include <fstream>
using namespace std;
/*
m_attr:
0: married
1->4: no OfChildren
5: union
6: WorkingRemote

*/

struct Employee {
   int m_id;
   struct {
      unsigned married : 1;
      unsigned noOfCh : 4;
      unsigned un : 1;
      unsigned wr : 1;
   } m_attr;
};


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
   Employee E;
   E.m_attr.married = 1;
   E.m_attr.noOfCh = 12;
   cout << E.m_attr.noOfCh << endl;
   return 0;
}
