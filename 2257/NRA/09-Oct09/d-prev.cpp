#include <iostream>
#include <vector>
#include <iterator>

int main() {
   std::vector<int> nums = { 10, 20, 30, 40, 50 };
   auto it = std::prev(nums.end(), 2);

   std::cout << "Value at previous iterator: " << *it << "\n"; // Output: Value at previous iterator: 40
   return 0;
}