#include <iostream>

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

   foo<int>();    // template instantiation 
   foo<double>(); // template instantiation
   return 0;
}
