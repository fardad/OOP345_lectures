#include <iostream>
#include <vector>
#include <functional>
using namespace std;
int main() {
   vector<int> v(6, 20);
   vector<reference_wrapper<int>> r(v.begin(), v.end());
   for (auto& i : v) {
      cout << i << " ";
   }
   cout << endl;
   for (auto& j : r) {
      j *= 5;
   }
   for (auto& i : v) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}