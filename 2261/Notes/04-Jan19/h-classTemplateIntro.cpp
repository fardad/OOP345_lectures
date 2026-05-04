#include <iostream>
using namespace std;
template <typename T>
class Array {
   T a[50];
   unsigned n{};
   T dummy{};
public:
   Array( ) = default;
   T& operator[]( unsigned i );
};

template<typename T>
T& Array<T>::operator[]( unsigned i ) {
   return i < 50 ? a[i] : dummy;
}


int main( ) {
   Array<int> I;
   Array<double> D;
   return 0;
}
