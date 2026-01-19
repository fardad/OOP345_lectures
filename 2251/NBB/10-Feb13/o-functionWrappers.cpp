#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void line(int num) {
   for (size_t i = 0; i < num; i++, std::cout << "-");
}

int main() {
   std::vector<int> nums = { 1, 2, 3, 4, 5 };
   std::function<void(int)> print = [](int n) { std::cout << n << " "; };
   std::function<void(int)> prnline = line;
   std::for_each(nums.begin(), nums.end(), print);
   // Output: 1 2 3 4 5

   return 0;
}
