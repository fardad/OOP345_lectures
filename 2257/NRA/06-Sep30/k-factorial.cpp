// file: recursion.cpp
#include <iostream>
using namespace std;

unsigned factorial(unsigned x) {
   if (x <= 2u) {
      return x;
   }
   else {
      return x * factorial(x - 1);
   }
  
}

int main() {
   cout << "4! = " << factorial(4) << endl;
   return 0;
}