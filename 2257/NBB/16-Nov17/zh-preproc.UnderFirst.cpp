// undef.cpp
#undef ZERO
#define ZERO (0)




#define VERSION 1

#include <iostream>

int main() {
   std::cout << "Version: " << VERSION << std::endl;

#undef VERSION
#define VERSION 2

   std::cout << "New Version: " << VERSION << std::endl;
   return 0;
}