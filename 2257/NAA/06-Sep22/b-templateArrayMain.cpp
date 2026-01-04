#include <iostream>
#include "Array.h"
using namespace std;
using namespace seneca;

int main() {
   cout << "06-Sep22 OOP345 NAA" << endl;
   Array<int> I(3);
   Array<double> D(2);
   for (int i = 0; i < 5; i++) {
      I[i] = i + 10;
   }
   cout << "*" << I << "*" << endl;

   for (int i = 0; i < 5; i++) {
      D[i] = i + 10.1123;
   }
   cout << "*" << D << "*" << endl;
   return 0;
}