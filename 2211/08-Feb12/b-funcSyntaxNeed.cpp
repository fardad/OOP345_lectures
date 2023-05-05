#include <iostream>
using namespace std;
template <typename Atype, typename Btype>
auto add(Atype A, Btype B)-> decltype(A + B) {
   return A + B;
}

auto main()->int {
   auto x = 10;
   int y = 20;
   int z;
   z = add(x, y);
   cout << z << endl;
   return 0;
}