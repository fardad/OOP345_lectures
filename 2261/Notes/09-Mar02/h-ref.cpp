// ref_bind.cpp
#include <iostream>
#include <functional>

void decrement(int& x, int& y) { --x; --y; }
void foo(int x, int y){ //whatever;
}
int main() {
   int a = 50, b = 30;
   auto dec = std::bind(decrement, std::ref(a), b);  // b copied, not ref
   dec();
   std::cout << "a = " << a << ", b = " << b << std::endl;
   return 0;
}
