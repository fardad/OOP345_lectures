// bind.cpp
#include <iostream>
#include <functional>

double divide(double x, double y) { return x / y; }

int main() {

   auto p = std::bind(divide, 100, 4);
   std::cout << "Quotient = " << p() << std::endl;
   return 0;
}