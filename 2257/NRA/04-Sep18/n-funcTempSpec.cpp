#include <iostream>
using namespace std;
#include <cstring>

template <typename T>
T maximum(T a, T b) {
   return a > b ? a : b;
}

// Specialization for const char*
template <>
const char* maximum<const char*>(const char* a, const char* b) {
   return strcmp(a, b) > 0 ? a : b;
}


//// you can use overload instead of specialization but then the function will always exist in the binary
//const char* maximum(const char* a, const char* b) {
//   return strcmp(a, b) > 0 ? a : b;
//}

int main() {
   cout << maximum(2.3, 4.5) << endl;       // generic version
   cout << maximum("abc", "def") << endl;   // specialization
   return 0;
}