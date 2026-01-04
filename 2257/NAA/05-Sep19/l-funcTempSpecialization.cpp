// maximum.h
#include <cstring>

template <typename T>
T maximum(T a, T b) {
   return a > b ? a : b;
}

template<>
const char* maximum<const char*>(const char* a, const char* b) {
   return strcmp(a, b) > 0 ? a : b;
}

//const char* maximum(const char* a, const char* b) {
//   return strcmp(a, b) > 0 ? a : b;
//}

#include <iostream>
//#include "maximum.h"
using namespace std;

int main() {
   int a = 123;
   double d = 345.66;
   cout << maximum(2.3, 4.5) << endl;       // generic version
   cout << maximum("abc", "def") << endl;   // specialization
   cout << maximum<double>(a, d);
   return 0;
}
