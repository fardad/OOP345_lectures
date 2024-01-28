#include <iostream>
using namespace std;

/*
foo(n) is OK
foo(n-1) we know this works   ===>  foo(n)   if I can proove this
AND
foo(1)  works ok too
*/
size_t fact(size_t num) {
   if(num == 1) {
      return 1;
   }
   else {
      return num * fact(num - 1);
   }
}
// n = n * n-1 * n- 2..... 1
auto hanoi(int n, char pa, char pb, char pc)->void {
   static size_t row{1};
   if(n == 1) {
      cout << row++ << "- Move from " << pa << " to " << pb << endl;
   }
   else {
      hanoi(n - 1, pa, pc, pb);
      cout << row++ << "- Move from " << pa << " to " << pb << endl;
      hanoi(n - 1, pc, pb, pa);
   }
}

auto main() -> int {
   cout << fact(4) << endl;
   hanoi(4, 'A', 'B', 'C');
   return 0;
}
