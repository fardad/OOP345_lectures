#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int main() {
   int a = 10, b = 5, c = 15;

   std::vector<std::reference_wrapper<int>> refs = { a, b, c };

   std::sort(refs.begin(), refs.end());

   for (int& ref : refs)
      std::cout << ref << " ";
   // Output: 5 10 15

   return 0;
}
