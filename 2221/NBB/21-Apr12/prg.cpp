#include <iostream>
#include <fstream>
#include <iomanip>
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
   unsigned m_attr;
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
   Employee E;
   E.m_attr = 0x1;
   unsigned noOch_mask = 9;
   cout << E.m_attr << endl;
   bitPattern(E.m_attr);
   noOch_mask <<= 1;
   E.m_attr = E.m_attr | noOch_mask;
   bitPattern(noOch_mask);
   bitPattern(E.m_attr);
   E.m_attr = E.m_attr | (1 << 6);
   bitPattern(E.m_attr);
   E.m_attr = E.m_attr & ~1;
   bitPattern(E.m_attr);
   E.m_attr = E.m_attr & ~(1 << 6);
   bitPattern(~(1 << 6));
   bitPattern(E.m_attr);

/*
   int value = 233434;
   cout <<"*"<< bits(32) << value << "*" << endl;
   *0011000*<newline>
*/
   return 0;
}



