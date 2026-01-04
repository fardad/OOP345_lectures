// side_effects.cpp
#define SQUARE(X) ((X) * (X))

#include <iostream>

int main() {
   int num = 3;
   std::cout << SQUARE(num++) << std::endl;  // num incremented twice! Outputs 9 or 12 (undefined)
   std::cout << "Num now: " << num << std::endl;  // 5
   return 0;
}