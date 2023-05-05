#include <iostream>
using namespace std;

template <typename T, int Tsize>
class Array {
   T a[Tsize];
public:
   int size() {
      return Tsize;
   }
   Array() {
   }
   T& operator[](unsigned index);
   virtual ~Array() {
   }
};

template <class T, int Tsize>
T& Array<T, Tsize>::operator[](unsigned index) {
   return a[index % Tsize];
}


int main() {
   Array<double, 10> a, b;

   for (int i = 0; i < a.size(); i++)
      a[i] = i * (i + .01);
   b = a;
   for (int i = 0; i < 30; i++)
      std::cout << b[i] << ' ';
   std::cout << endl;
}