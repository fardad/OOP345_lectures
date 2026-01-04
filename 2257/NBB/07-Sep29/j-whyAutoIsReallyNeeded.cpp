// file: decltype.cpp
#include <iostream>
using namespace std;

template<typename T, typename U>
auto add(const T& t, const U& u) -> decltype(t + u) {
   return t + u;
}

int main() {
   int i = 3, j = 6;
   double x = 4.5;

   auto res = add(i, x);

   cout << add(i, j) << endl;   // int + int
   cout << add(i, x) << endl;   // int + double
   return 0;
}