#include <iostream>
#include <vector>
#include <iterator>

int main() {
   std::vector<int> nums = { 10, 20, 30, 40, 50 };
   auto it = nums.begin();
   int steps = 6; // Advancing by 6 is out of range

   if (steps >= 0 && std::distance(it, nums.end()) >= steps) {
      std::advance(it, steps);
      std::cout << "Advanced to: " << *it << "\n";
   }
   else {
      std::cerr << "Error: Advancing out of bounds\n";
   }

   return 0;
}