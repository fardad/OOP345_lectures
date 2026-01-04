#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
   std::vector<int> nums = { 10, 20, 30 };
   std::vector<int> to_copy = { 40, 50 };

   std::copy(to_copy.begin(), to_copy.end(), std::back_inserter(nums));

   for (int n : nums)
      std::cout << n << " "; // Output: 10 20 30 40 50
   return 0;
}