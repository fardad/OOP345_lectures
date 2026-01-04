// bind.cpp
#include <iostream>
#include <functional>

void decrement(int& x, int& y) { --x; --y; }

int main() {
   int a = 50, b = 30;
   auto p = std::bind(decrement, std::ref(a), b);
   p();
   std::cout << "a: " << a << ", b:" << b << std::endl;
   return 0;
}