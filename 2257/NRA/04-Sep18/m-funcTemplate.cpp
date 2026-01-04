#include <iostream>
using namespace std;
template <typename T>
void Swap(T& a, T& b) {
   T c = a;
   a = b;
   b = c;
}



int main() {
   double x = 2.3, y = 4.5;
   Swap(x, y);
   cout << "Swapped: " << x << ", " << y << endl;

   long a = 78, b = 567;
   Swap(a, b);
   cout << "Swapped: " << a << ", " << b << endl;
   return 0;
}