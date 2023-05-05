#include <iostream>
using namespace std;

template <typename T = int, int Tsize = 100>
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
   Array<long> a, b;

   for (int i = 0; i < a.size(); i++)
      a[i] = i * i;
   b = a;
   for (int i = 0; i < a.size(); i++)
      std::cout << b[i] << ' ';
   std::cout << endl;
}
