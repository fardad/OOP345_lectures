#include <iostream>
using namespace std;

#include <iostream>
#include <cstring>

template <class T>
T maximum(T a, T b) {
   std::cout << "in template body\n";
   return a > b ? a : b;
}

// specialization for char* types
//
template <> // denotes specialization
const char* maximum<const char*>(const char* a,
   const char* b) {
   std::cout << "in specialization\n";
   return std::strcmp(a, b) > 0 ? a : b;
}


// Template Specialization
// maximum_overload.cpp

const char* maximum(const char* a, const char* b) {
   std::cout << "in overloaded function\n";
   return std::strcmp(a, b) > 0 ? a : b;
}

int main() {
   double a = 2.32;
   double b = 4.56;
   const char* d = "abc";
   const char* e = "def";

   double c = maximum(a, b);

   std::cout << "Greater of " <<
      a << ", " << b <<
      " is " << c << std::endl;

   const char* f = maximum(d, e);

   std::cout << "Greater of " <<
      d << ", " << e <<
      " is " << f << std::endl;
   return 0;
}