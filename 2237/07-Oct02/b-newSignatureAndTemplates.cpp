#include <iostream>
using namespace std;

template <typename Lt, typename Rt>
auto add(Lt a , Rt b)->decltype(a+b) {
   return a + b;
}


auto main() -> int {
   cout << "OOP345 NBB 07-Oct02" << endl;
   int a = 10;
   long long x = 300000000000LL, y;
   double d = 30.3;
   double res;
   y = add(x, a);
   cout << y << endl;
   res = add(a, d);
   cout << res << endl;
   return 0;
}
