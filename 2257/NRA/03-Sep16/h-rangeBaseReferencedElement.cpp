// array.cpp
#include <iostream>
using namespace std;
void foo(int array[]) {
   cout << "in foo: " << sizeof(array) << endl;
}

int main() {
   int a[5]{ 1, 2, 3, 4, 5 }; // aggregate initialization
   for (int& e : a) {
      cout << e << " ";
      e += 10;
   }
   cout << endl;
   for (int e : a) {
      cout << e << " ";
   }
   cout << endl;
   cout << "Size of array in main: " << sizeof(a) << endl;
   foo(a);
   return 0;
}