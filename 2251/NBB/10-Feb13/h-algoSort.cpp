#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> nums = { 7, 3, 9, 1, 5 };
   // the type of the vector should support comparison
   std::sort(nums.begin(), nums.end());

   for (int n : nums)
      std::cout << n << " ";
   return 0;
}