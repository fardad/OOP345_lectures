#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> nums = { 1, 3, 5, 7, 9 };
   bool exists = std::binary_search(nums.begin(), nums.end(), 5);

   std::cout << (exists ? "Found" : "Not Found") << "\n";
   return 0;
}

