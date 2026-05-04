#include <iostream>
#include <vector>
using namespace std;
int main() {
   cout << "OOP345 NBB - Feb 09" << endl;
   vector<int> numbers = { 10, 20, 30 };

   for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
      cout << *it << " ";  // Dereference the iterator to access the value
   }
   return 0;
}