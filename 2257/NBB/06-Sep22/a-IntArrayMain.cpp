#include <iostream>
#include "IntArray.h"
using namespace seneca;
using namespace std;
int main() {
   cout << "06-Sep22 OOP345 NBB" << endl;
   IntArray ar(5);
   for (int i = 0; i < 10; i++) {
      ar[i] = i + 10;
   }
   cout << ar << endl;
   return 0;
}