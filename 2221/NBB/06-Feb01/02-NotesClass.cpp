#include <iostream>
using namespace std;

template <class T>
class Array {
   T a[50];
public:
   Array() {
   }
   T& operator[](unsigned index);
   virtual ~Array() {
   }
};

template <class T>
T& Array<T>::operator[](unsigned index) {
   return a[index % 50];
}


int main() {
   Array<double> a, b;

   for (int i = 0; i < 60; i++)
      a[i] = i + 10.1234;
   b = a;
   for (int i = 0; i < 60; i++)
      std::cout << b[i] << ' ';
   std::cout << endl;
}