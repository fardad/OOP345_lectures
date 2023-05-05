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

int main() {
   cout << fact(4) << endl;
   return 0;
}