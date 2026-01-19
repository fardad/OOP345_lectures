#include <iostream>
#include "DynArray.h"
using namespace std;
using namespace seneca;
struct Container {
   int m_data;
   Container( int value = 10 ) {
      m_data = value;
   }
   Container& operator=( int value ) {
      m_data = value;
      return *this;
   }
};
ostream& operator<<( ostream& ostr, const Container C ) {
   return ostr << C.m_data;
}

int main( ) {
   DynArray<Container> C( 4 );
   DynArray<double> D( 5 );
   size_t i;
   for ( i = 0; i < 9; i++ ) {
      C[i] = i + 10;
   }
   cout << C << endl;
   for ( i = 0; i < 8; i++ ) {
      D[i] = (i + 1) * 10.2;
   }
   cout << D << endl;
   return 0;
}