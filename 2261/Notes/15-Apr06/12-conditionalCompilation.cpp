// conditional_logical.cpp
#define MODE 2

#include <iostream>

#if MODE == 1
#define OUTPUT "Mode One"
#elif MODE == 2
#define OUTPUT "Mode Two"
#else
#define OUTPUT "Default Mode"
#endif

int main() {
   std::cout << OUTPUT << std::endl;
   return 0;
}