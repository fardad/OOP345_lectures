#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> nums = { 1, 3, 5, 7, 9 };

   auto it = std::find(nums.begin(), nums.end(), 5);

   if (it != nums.end())
      std::cout << "Found: " << *it << " at " << std::distance(nums.begin(), it) << std::endl;
   else
      std::cout << "Not Found\n";

   return 0;
}