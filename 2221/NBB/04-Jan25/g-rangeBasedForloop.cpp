// Range-Based for
 // for_each.cpp

#include <iostream>
using namespace std;
int main() {
   int a[]{ 1, 2, 3, 4, 5, 6 };

   for (auto& e : a) {
      std::cout << unsigned(&e) << ": " << e << endl;
   }
   return 0;
}