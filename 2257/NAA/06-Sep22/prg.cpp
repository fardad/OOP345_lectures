#include <iostream>
#include "Array.h"
using namespace std;
using namespace seneca;

int main() {
   int a[10000];
   //....
   size_t cnt{};
   // counts number of elemnet in a with value more that 20)
   for (size_t i = 0; i < 10000; i++) {
      (a[i] > 20) && (cnt++);
   }
   return 0;
}