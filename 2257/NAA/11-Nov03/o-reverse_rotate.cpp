// reverse_rotate.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> v = { 1, 2, 3, 4, 5 };
   std::reverse(v.begin(), v.end());
   std::cout << "Reversed: ";
   for (int n : v) std::cout << n << " ";  // 5 4 3 2 1
   std::cout << std::endl;

   std::rotate(v.begin(), v.begin() + 2, v.end());  // Rotate left by 2
   std::cout << "Rotated: ";
   for (int n : v) std::cout << n << " ";  // 3 2 1 5 4
   std::cout << std::endl;
   return 0;
}