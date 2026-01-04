/ count.cpp
#include <iostream>
#include <array>
#include <algorithm>

int main() {
   std::array<int, 9> a = { 7, 14, 21, 3, 28, 35, 14, 42, 49 };
   int n = std::count(a.begin(), a.end(), 14);
   std::cout << "14 occurs " << n << " times.\n";

   int multiples_of_7 = std::count_if(a.begin(), a.end(), [](int i) { return i % 7 == 0; });
   std::cout << "Multiples of 7: " << multiples_of_7 << std::endl;
   return 0;
}