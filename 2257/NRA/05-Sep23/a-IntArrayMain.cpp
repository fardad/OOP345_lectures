#include <iostream>
#include "IntArray.h"
using namespace seneca;
using namespace std;
int main() {
   cout << "05-Sep23 OOP345 NRA" << endl;
   IntArray I(4);

   for (size_t i = 0; i < 20; i++) {
      I[i] = i + 10;
   }
   cout << I << endl;
   return 0;
}