// File: bind_3_to_2.cpp
#include <iostream>
#include <functional>
using namespace std;

int compute(int a, int b, int scale) {
   return (a + b) * scale;
}

// A "function wrapper" that expects a callable with TWO args.
int wrapper2(const function<int(int, int)>& fn, int x, int y) {
   return fn(x, y);
}

int main() {
   using namespace std::placeholders;

   // Adapt compute(a, b, scale) into a callable that takes ONLY (a, b).
   // Here scale is fixed to 10.
   function<int(int, int)> twoArgFn = bind(compute, _1, _2, 10);

   cout << wrapper2(twoArgFn, 2, 3) << endl;  // (2+3)*10 = 50
   cout << wrapper2(twoArgFn, 7, 1) << endl;  // (7+1)*10 = 80

   return 0;
}