#include <iostream>
using namespace std;
template <typename T, typename U>
auto add(T a, U b)->decltype(a+b) {
   return a + b;
}
auto main()->int {
   cout << "OOP345 NBB - Feb 02" << endl;
   int a = 10, b = 20;
   double x = 10.1, y = 20.2;
   auto r1 = add(a, x);
   auto r2 = add(a, b);
   auto r3 = add(x, y);

   cout << r1 << endl;
   cout << r2 << endl;
   cout << r3 << endl;

   return 0;
}

