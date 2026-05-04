#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int add(int x, int y) {
   return x + y;
}

//int add5(int x) {
//   return add(x, 5);
//}

int main() {

   auto add5 = std::bind(add, std::placeholders::_1, 5);

   vector<int> nums = { 1, 2, 3 };
   vector<int> res(nums.size());

   transform(nums.begin(), nums.end(), res.begin(), add5);

   for (int r : res) {
      cout << r << " ";
   }

   return 0;
}
