#include <iostream>
#include "Array.h"
using namespace seneca;
using namespace std;
int main() {
   cout << "06-Sep22 OOP345 NBB" << endl;
   Array<int> ar(5);
   Array<double> D(5);
   for (int i = 0; i < 10; i++) {
      ar[i] = i + 10;
   }
   cout << ar << endl;
   for (int i = 0; i < 10; i++) {
      D[i] = i + 10.1234;
   }
   cout << D << endl;
   return 0;
}