#include <iostream>
#include "Array.h"
using namespace seneca;
using namespace std;
const size_t asize = 1000000;
int main() {
   cout << "06-Sep22 OOP345 NBB" << endl;
   int a[asize];
   size_t negs{}, pos{};
   //....
   for (size_t i = 0; i < asize; i++) {
      (a[i] < 0) && (negs++);
      (a[i] < 0) || (pos++);
   }

   return 0;
}