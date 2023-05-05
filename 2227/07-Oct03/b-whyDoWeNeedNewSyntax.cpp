#include <iostream>
using namespace std;
template <typename At, typename Bt>
auto add(At a, Bt b)->decltype(a, b) {
   return a + b;
}
auto main()->int {
   int a = 10;
   double b = 30;
   double c;
   c = add(a, b);
   cout << c << endl;
   return 0;
}