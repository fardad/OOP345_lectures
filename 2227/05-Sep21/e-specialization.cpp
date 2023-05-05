#include <iostream>
#include <cstring>
using namespace std;
class Employee;
template <class T>
T maximum(T a, T b) {
   return a > b ? a : b;
}

///This is just for example and there is no need for it
template <> // specialization
int maximum<int>(int a, int b) {
   cout << "the int specializtion is called!" << endl;
   return a > b ? a : b;
}

template<>
Employee* maximum<Employee*>(Employee* a, Employee* b) {
   // do whatever needed
   return whatever;
}

template <>   // specialization
const char* maximum<const char*>(const char* a, const char* b) {
   return strcmp(a, b) > 0 ? a : b;
}


int main() {
   return 0;
}
