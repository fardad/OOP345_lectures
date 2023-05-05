#include <iostream>
#include <functional>
#include <vector>
using namespace std;


int main() {
   vector<int> v(6, 20);
   vector<reference_wrapper<int>> r(v.begin(), v.end());
   int val = 10;
   for(auto& i: v) {
      cout << i << " ";
   }
   cout << endl;
   for(auto& j : r) {
      j += val++;
   }
   for(auto& i : v) {
      cout << i << " ";
   }
   return 0;
}
