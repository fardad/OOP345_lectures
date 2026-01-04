// precedence.cpp
#define BAD_MULT(X, Y) X * Y  // Wrong: 2 + 3 * 4 -> 2 + 12 = 14 (expected 20)
#define GOOD_MULT(X, Y) ((X) * (Y))  // Fixed

#include <iostream>

int main() {
   std::cout << "Bad: " << BAD_MULT(2 + 3, 4) << std::endl;  // 14
   std::cout << "Good: " << GOOD_MULT(2 + 3, 4) << std::endl;  // 20
   return 0;
}