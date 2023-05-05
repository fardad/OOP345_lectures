#include <iostream>
using namespace std;
template <class T>
void faa(T a) {
   std::cout << a << std::endl;
}


template <typename T> // template header 
void foo() {
   T value;
   value = 1.5;
   std::cout << value << '\n';
}

int main() {
   return 0;
}
