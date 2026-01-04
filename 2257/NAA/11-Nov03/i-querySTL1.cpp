// all_any_none.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
   std::vector<int> v = { 2, 4, 6, 8 };
   bool all_even = std::all_of(v.begin(), v.end(), [](int n) { return n % 2 == 0; });
   bool any_odd = std::any_of(v.begin(), v.end(), [](int n) { return n % 2 != 0; });
   bool none_neg = std::none_of(v.begin(), v.end(), [](int n) { return n < 0; });

   std::cout << "All even: " << all_even << std::endl;
   std::cout << "Any odd: " << any_odd << std::endl;
   std::cout << "None negative: " << none_neg << std::endl;
   return 0;
}