#include <iostream>
using namespace std;
template <typename T, int SIZE>
class Array {
   T a[SIZE];
   T dummy{};
public:
   Array( ) = default;
   T& operator[]( unsigned i ) {
      return i < SIZE ? a[i] : dummy;
   }
   void foo( );
};

template <typename T, int Size>
void Array<T, Size>::foo( ) {
   //whatever;
}

int main( ) {
   Array<int, 100> I;
   Array<int, 100> J;
   Array<int, 200> K;
   Array<double, 200> D;

   return 0;
}
