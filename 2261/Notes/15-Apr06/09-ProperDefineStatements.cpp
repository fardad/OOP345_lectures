
#include <iostream>

#ifdef ZERO
#  undef ZERO
#endif // ZERO

#define ZERO (0) // a safe compile error free define statement 

#ifdef ADD
#  undef ADD
#endif // ADD

#define ADD(x, y)  ((x) + (y)) // a safe compile error free macro definition.

int main() {
   std::cout << "ZERO IS FOR SURE " << ZERO << std::endl;
   return 0;
}