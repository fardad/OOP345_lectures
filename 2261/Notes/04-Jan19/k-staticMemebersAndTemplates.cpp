#include <iostream>
using namespace std;
template <typename T, int SIZE=100>
class Array {
   static unsigned count;
public:
   Array( ) { ++count; }
   ~Array( ) { --count; }
   static unsigned getCount( ) { return count; }
};

template <typename T, int SIZE>
unsigned Array<T, SIZE>::count = 0;

int main( ) {
   Array<int> I;

   return 0;
}
