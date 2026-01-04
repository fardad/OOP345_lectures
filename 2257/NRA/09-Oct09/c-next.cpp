#include <iostream>
#include <vector>
#include <iterator>

int main() {
   std::vector<int> nums = { 10, 20, 30, 40, 50 };
   auto it = std::next(nums.begin(), 3);

   std::cout << "Value at next iterator: " << *it << "\n"; // Output: Value at next iterator: 40
   return 0;
}