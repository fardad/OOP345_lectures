#include <iostream>
using namespace std;

template <typename T = int, int Tsize = 100>
class Array {
   T a[Tsize];
   static unsigned noOfArrayObjects;
public:
   static unsigned count() {
      return noOfArrayObjects;
   }
   int size() {
      return Tsize;
   }
   Array() {
      noOfArrayObjects++;
   }
   T& operator[](unsigned index);
   virtual ~Array() {
      noOfArrayObjects--;
   }
};

template <class T = int, int Tsize = 100>
unsigned Array<T, Tsize>::noOfArrayObjects = 0u;





template <class T = int, int Tsize = 100>
T& Array<T, Tsize>::operator[](unsigned index) {
   return a[index % Tsize];
}

int main() {
   Array<> s, t;
   Array<double> u;
   Array<int, 40> v;

   std::cout << Array<>::count() << std::endl;
   std::cout << Array<double>::count() << std::endl;
   std::cout << Array<int, 40>::count() << std::endl;
