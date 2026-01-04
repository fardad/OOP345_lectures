// array.cpp
#include <iostream>
using namespace std;

int main() {
   int a[5]{ 1, 2, 3, 4, 5 }; // aggregate initialization

   for (int elem : a)    // only works in the same scope of the array
      cout << elem << " ";
   cout << endl;
   return 0;
}