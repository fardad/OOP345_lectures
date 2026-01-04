#include <iostream>
#include <vector>
#include <ranges>

int main() {
   std::vector<int> nums = { 10, 20, 30, 40, 50 };
   auto it = nums.begin();

   std::ranges::advance(it, 3); // Safe version of std::advance
   std::cout << "Advanced to: " << *it << "\n";

   return 0;
}