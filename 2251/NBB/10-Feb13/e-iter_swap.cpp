#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> nums = { 10, 20, 30, 40, 50 };
   auto it1 = nums.begin();
   auto it2 = std::next(nums.begin(), 3);

   std::iter_swap(it1, it2);

   for (int n : nums)
      std::cout << n << " "; // Output: 40 20 30 10 50
   return 0;
}