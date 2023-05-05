#include "module.h"
#include <iostream>

int main() {
   int mark = 60;
   if (mark < MinPassGrade) std::cout << "fail";

   int i;//  function scope
   std::cout << "Enter i : ";
   std::cin >> i;
   if (i < 0) {
      int i = 4;  // shadows the outer i   block scope
      std::cout << i << std::endl;
   }
   else {
      int i = -4; // shadows the outer i
      std::cout << i << std::endl;
   }
   std::cout << i << std::endl;
}