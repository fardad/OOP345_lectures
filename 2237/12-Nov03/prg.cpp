#include <iostream>
#include <functional>
using namespace std;

template <typename T, size_t size>
class Array {
   T data[size]{};
   T garbage{ };
public:
   Array( ) = default;
   T& operator[]( size_t index ) {
      T* temp = garbage;
      if ( index < size ) {
         temp =& data[index];
      }
      return *temp;
   }
};


int main( ) {
   int a = 10, b = 10;
   auto addone = bind( inc, ref(a), b );

   addone( );
   cout << "a: " << a << ",b: " << b << endl;

   return 0;
}