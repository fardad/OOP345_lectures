#include <iostream>
#include "foo.h";
int i;
int main() {
   int j;
   int i;
   if (cond) {
      int i;
      // i dies here
   }
}

void foo() {
   i = 10;
   sdds::trueGlobal = 265;
}