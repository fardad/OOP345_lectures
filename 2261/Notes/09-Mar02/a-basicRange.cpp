#include <iostream>
#include <vector>
#include <algorithm>  // For algorithms
using namespace std;
int main() {
   cout << "OOP345 NBB - Mar02" << endl;
   std::vector<int> data = { 1, 2, 3, 4, 5 };
   std::cout << "Original range: ";
   for (auto it = data.begin(); it != data.end(); ++it) {
      std::cout << *it << " ";
   }
   std::cout << std::endl;

   return 0;
}