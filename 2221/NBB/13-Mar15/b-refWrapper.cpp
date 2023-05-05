#include <iostream>
#include <vector>
#include <functional>
using namespace std;
int main() {
   vector<int> v(10, 20);
   for (auto i : v) {
      cout << i << " ";
   }
   cout << endl;
   vector < reference_wrapper<int>> R(v.begin(), v.end());
   for (auto i : R) {
      i *= 3;
   }
   for (auto i : v) {
      cout << i << " ";
   }
   cout << endl;

   return 0;
}