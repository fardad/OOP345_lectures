#include <iostream>
#include <vector>
#include <iterator>

int main() {
   std::vector<int> nums = { 10, 20, 30, 40, 50 };
   auto it = nums.begin();

   std::advance(it, 2);
   std::cout << "Value at advanced iterator: " << *it << "\n"; // Output: Value at advanced iterator: 30
   return 0;
}