#include <iostream>

template <typename T>
void swap(T& a, T& b) {
   T c;
   c = a;
   a = b;
   b = c;
}

int main() {

   double a = 2.3;
   double b = 4.5;
   char   d = 'A';
   char   e = 'B';
   swap(a, b);
   std::cout << "Swapped values are " <<
      a << " and " << b << std::endl;
   swap(d, e);
   std::cout << "Swapped values are " <<
      d << " and " << e << std::endl;
   return 0;
}