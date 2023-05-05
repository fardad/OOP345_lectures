#include <iostream>
using namespace std;
void hanoi(int n, char ta, char tb, char tc) {
   static int row = 1;
   if (n == 1) {
      cout << row++ << "- move from " << ta << " to " << tb << endl;
   }
   else {
      hanoi(n - 1, ta, tc, tb);
      cout << row++ << "- move from " << ta << " to " << tb << endl;
      hanoi(n - 1, tc, tb, ta);
   }
}


// X =4;
// 1 * 2 * 3 * 4

auto main()->int {
   hanoi(50, 'A', 'B', 'C');
  
   return 0;
}