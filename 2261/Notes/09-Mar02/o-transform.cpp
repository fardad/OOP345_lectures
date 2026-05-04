// transform.cpp
#include <iostream>
#include <vector>
#include <algorithm>
// check:
// fill(v.begin(), v.end(), val);
// replace_if(v.being(), v.end(), funcWrapper bool(v element)
// remove_f(v.being(), v.end(), funcWrapper bool(v element)
int cube(int x) { return x * x * x; }

int main() {
   std::vector<int> src = { 1, 2, 3, 4, 5 };
   std::vector<int> dest(5);

   std::transform(src.begin(), src.end(), dest.begin(), cube);
   std::cout << "Cubed: ";
   for (int n : dest) std::cout << n << " ";
   std::cout << std::endl;
   return 0;
}