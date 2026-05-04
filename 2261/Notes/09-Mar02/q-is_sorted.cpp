// is_sorted.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> v = { 1, 3, 2, 4 };
   bool sorted = std::is_sorted(v.begin(), v.end());
   std::cout << "Is sorted: " << sorted << std::endl;  // 0
   return 0;
}