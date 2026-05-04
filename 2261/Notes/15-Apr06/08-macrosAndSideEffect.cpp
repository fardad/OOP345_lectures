// side_effects.cpp
#define SQUARE(X) ((X) * (X))
template<typename type>
type square(type x) { return x * x; }
#include <iostream>

int main() {
   int num = 3;
   std::cout << SQUARE(num++) << std::endl;  // num incremented twice! Outputs 9 or 12 (undefined)
   //std::cout << ((num++)  * (num++)) << std::endl;
   std::cout << "Num now: " << num << std::endl;  // 5
   num = 3;
   std::cout << square(num++) << std::endl;
   std::cout << "Num now: " << num << std::endl;  // 4
   return 0;
}