#include <iostream>
using namespace std;

template <typename T = int, int SIZE = 50>
class Array {
   T a[SIZE];
   T dummy{};
public:
   Array( ) = default;
   T& operator[]( unsigned i ) {
      return i < SIZE ? a[i] : dummy;
   }
};


int main( ) {
   Array<> I;

   return 0;
}
