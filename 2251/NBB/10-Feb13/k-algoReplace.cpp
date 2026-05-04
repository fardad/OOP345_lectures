#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> nums = { 1, 2, 2, 4, 5 };
   std::replace(nums.begin(), nums.end(), 2, 9);

   for (int n : nums)
      std::cout << n << " ";
   return 0;
}