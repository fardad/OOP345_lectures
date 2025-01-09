#include <vector>
#include <iostream>
using namespace std;
int main() {
   vector<int> nums;
   vector<int>::iterator i;

   nums.push_back(10);
   nums.push_back(20);
   nums.push_back(30);
   nums.push_back(40);

   for (i = nums.begin(); i != nums.end(); i++) {
      cout << *i << " ";
   }
   cout << endl;
   return 0;
}