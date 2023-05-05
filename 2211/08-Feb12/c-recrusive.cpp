#include <iostream>
using namespace std;
unsigned fact(unsigned X) {
   if (X == 1) {
      return 1;
   }
   else {
      return X * fact(X - 1);
   }
}
// X =4;
// 1 * 2 * 3 * 4

auto main()->int {
   unsigned V;
   V = fact(4);
   cout << V << endl;
  
   return 0;
}