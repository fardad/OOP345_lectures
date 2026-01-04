// sort.cpp
#include <iostream>
#include <vector>
#include <algorithm>
// check stable_sort
int main() {
   std::vector<int> v = { 5, 3, 8, 1, 4 };
   std::sort(v.begin(), v.end());
   std::cout << "Sorted: ";
   for (int n : v) std::cout << n << " ";  // 1 3 4 5 8
   std::cout << std::endl;

   // Custom comparator (descending)
   std::sort(v.begin(), v.end(), std::greater<int>());
   std::cout << "Descending: ";
   for (int n : v) std::cout << n << " ";  // 8 5 4 3 1
   std::cout << std::endl;
   return 0;
}