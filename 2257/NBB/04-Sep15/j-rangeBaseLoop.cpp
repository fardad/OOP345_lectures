// array.cpp
#include <iostream>
using namespace std;

int main() {
   int a[5]{ 1, 2, 3, 4, 5 }; // aggregate initialization
   for (int elem : a) {
      cout << elem << " ";
      elem = 0;
   }
   cout << endl;
   for (int elem : a) {
      cout << elem << " ";
   }
   cout << endl;
   return 0;
}