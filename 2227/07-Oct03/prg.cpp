#include <iostream>
using namespace std;
void hanoi(int n, char pa, char pb, char pc) {
   static int row = 1;
   if (n == 1) {
      cout << row++ << "- Move from " << pa << " to " << pb << endl;
   }
   else {
      hanoi(n - 1, pa, pc, pb);
      cout << row++ << "- Move form " << pa << " to " << pb << endl;
      hanoi(n - 1, pc, pb, pa);
   }
}


int main() {
   hanoi(40, 'A', 'B', 'C');
   return 0;
}