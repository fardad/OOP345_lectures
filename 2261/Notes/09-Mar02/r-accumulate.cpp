// accumulate.cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
   std::vector<int> v = { 1, 2, 3, 4, 5 };
   int sum = std::accumulate(v.begin(), v.end(), 0);
   std::cout << "Sum: " << sum << std::endl;  // 15

   // Product
   int prod = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
   std::cout << "Product: " << prod << std::endl;  // 120
   return 0;
}