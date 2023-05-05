#include <iostream>
using namespace std;
auto add(int a, int b)-> int {
   return a + b;
}

auto main()->int {
   auto x = 10;
   int y = 20;
   int z;
   z = add(x, y);
   cout << z << endl;
   return 0;
}