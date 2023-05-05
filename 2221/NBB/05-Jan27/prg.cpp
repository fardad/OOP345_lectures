#include <iostream>
#include <cstring>
using namespace std;
class Employee;

template <class T>
T maximum(T a, T b) {
   return a > b ? a : b;
}

template<>
Employee* maximum<Employee*>(Employee* a, Employee* b) {
   // whaever
   return a;
}


template <>   // specialization
const char* maximum<const char*>(const char* a, const char* b) {
   return strcmp(a, b) > 0 ? a : b;
}

template <> // specialization
int maximum<int>(int a, int b) {
   cout << "the int specializtion is called!" << endl;
   return a > b ? a : b;
}


int main() {

   double a = 0.1234;
   double b = 1010.10;
   int i = 12;
   int j = 25;
   const char* d = "DEF DEF DEF";
   const char* e = "ABC ABC ABC";

   double c = maximum(a, b);

   std::cout << "Greater of " <<
      a << ", " << b <<
      " is " << c << std::endl;

   const char* f = maximum(d, e);

   std::cout << "Greater of " <<
      d << ", " << e <<
      " is " << f << std::endl;
   int k = maximum(j, i);

   std::cout << "Greater of " <<
      j << ", " << i <<
      " is " << k << std::endl;
   return 0;
}