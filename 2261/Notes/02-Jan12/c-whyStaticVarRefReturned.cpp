#include <iostream>
using namespace std;
class Array {
   int el[20];
public:
   int& operator[](size_t index) {
      static int garbage{};
      int* ret = &garbage;
      if (index >= 0 && index <= 19) {
         ret = &el[index];
      }
      return *ret;
   }
};


int main() {
   cout << "OOP345 JAN12" << endl;
   Array a;
   a[5] = 20;
   a[30] = 5000;
   return 0;
}