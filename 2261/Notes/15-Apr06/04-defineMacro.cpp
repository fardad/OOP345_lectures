// func_single.cpp
#define DOUBLE_IT(X) (X + X)

#include <iostream>

int main() {
   int result = DOUBLE_IT(5);
   //int result = (5 + 5); //will expand to this before compilation
   std::cout << "Double 5: " << result << std::endl;
   return 0;
}