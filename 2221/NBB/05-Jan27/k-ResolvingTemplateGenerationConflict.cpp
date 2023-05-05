#include <iostream>
template <typename T>
T maximum(T a, T b) {
   return a > b ? a : b;
}

int main() {
   double a = 0.1234;
   double b = 1010.10;
   float d = 2.2;
   float e = 3.3F;

   double c = maximum<double>(a, d);

   std::cout << "Greater of " <<
      a << ", " << d <<
      " is " << c << std::endl;

   float f = maximum<float>(b, e);

   std::cout << "Greater of " <<
      b << ", " << e <<
      " is " << f << std::endl;

}