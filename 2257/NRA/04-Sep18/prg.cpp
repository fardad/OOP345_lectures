#include <iostream>
//#include "array.h"
using namespace std;
// array.h
template <typename T>
class Array {
   T a[50];
   unsigned n{};
   T dummy{};
public:
   Array() = default;
   T& operator[](unsigned i) {
      return i < 50 ? a[i] : dummy;
   }
};

int main() {
   Array<long> arr;
   for (int i = 0; i < 5; i++)
      arr[i] = i * i;

   for (int i = 0; i < 5; i++)
      cout << arr[i] << " ";
   cout << endl;
   return 0;
}