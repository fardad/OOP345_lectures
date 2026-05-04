#include <iostream>
#include "ADD.h"  // always add your costum headers after the library ones

int main() {
   std::cout << "NULL: " << NULL << std::endl;  
#undef NULL
#define NULL 1000
   std::cout << "NULL: " << NULL << std::endl;
   return 0;
}