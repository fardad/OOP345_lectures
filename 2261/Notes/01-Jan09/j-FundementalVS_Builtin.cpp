#include <iostream>
using namespace std;

int main() {
   // Fundamental types
   int x = 5;
   double y = 3.14;

   // Built-in but not fundamental
   int arr[3] = { 1, 2, 3 };   // array
   int& ref = x;             // reference
   enum Color { Red, Blue }; // enumeration
   Color c = Red;

   cout << "x = " << x << ", y = " << y << endl;
   cout << "arr[0] = " << arr[0] << endl;
   cout << "ref = " << ref << endl;
   cout << "c = " << c << endl; // prints 0 (Red)
}