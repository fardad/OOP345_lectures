//[first, last)

// intro_range.cpp - Basic STL range demo
#include <iostream>
#include <vector>
#include <algorithm>  // For algorithms

int main() {
   std::vector<int> data = { 1, 2, 3, 4, 5 };
   std::cout << "Original range: ";
   for (auto it = data.begin(); it != data.end(); ++it) {
      std::cout << *it << " ";
   }
   std::cout << std::endl;
   return 0;
}