#include <iostream>
using namespace std;
int main() {
   cout << "OOP345 NAA - May 26" << endl;
   int x = 2 + 3 * 4;   // Multiplication first: 2 + (3*4) = 14
   int y = (2 + 3) * 4; // Parentheses force addition first: 20

   cout << "x = " << x << ", y = " << y << endl;
   return 0;
}