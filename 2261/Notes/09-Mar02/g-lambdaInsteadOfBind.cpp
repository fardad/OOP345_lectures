// File: bind_reorder.cpp
#include <iostream>
#include <functional>
using namespace std;

int compute(int a, int b, int scale) {
   return (a + b) * scale;
}

int wrapper2(const function<int(int, int)>& fn, int x, int y) {
   return fn(x, y);
}

int main() {
   using namespace std::placeholders;
   auto twoArgFn = [](int a, int b) { return compute(a, b, 10); };
   // Swap: call compute(y, x, 10) even though wrapper gives (x, y)
   function<int(int, int)> swapped = bind(compute, _2, _1, 10);

   cout << wrapper2(swapped, 2, 3) << endl; // compute(3,2,10) -> 50
   cout << wrapper2(swapped, 10, 1) << endl; // compute(1,10,10) -> 110

   return 0;
}