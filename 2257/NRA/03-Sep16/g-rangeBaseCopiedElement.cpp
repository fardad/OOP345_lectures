// array.cpp
#include <iostream>
using namespace std;

int main() {
   int a[5]{ 1, 2, 3, 4, 5 }; // aggregate initialization
   for (int e : a) {
      cout << e << " ";
      e += 10;
   }
   cout << endl;
   for (int e : a) {
      cout << e << " ";
   }
   cout << endl;
   return 0;
}