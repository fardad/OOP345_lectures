#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> nums = { 1, 2, 3, 4, 5 };
   std::vector<int> res(5, 0);
   std::transform(nums.begin(), nums.end(), res.begin(), [](int n) { return n * 2; });

   for (int n : res)
      std::cout << n << " ";
   return 0;
}