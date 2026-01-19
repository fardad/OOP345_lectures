#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> nums = { 1, 2, 3, 4, 5 };
   std::transform(nums.begin(), nums.end(), nums.begin(), [](int n) { return n * 2; });
   // nums.begin();; start the range to transform
   // nums.end(); endo of the reange to transform
   // nums.begin(); start of the destination rage (can overwrite source)
   for (int n : nums)
      std::cout << n << " ";
   return 0;
}