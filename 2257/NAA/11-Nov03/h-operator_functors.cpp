// operator_functor.cpp
#include <iostream>
#include <functional>

int main() {
   std::minus<int> sub;
   std::cout << sub(8, 3) << std::endl;
   return 0;
}