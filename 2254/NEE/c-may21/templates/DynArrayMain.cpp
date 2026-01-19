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
   DynArray<double> D( 2 );
   DynArray<Container> C( 4 );
   int i;
   for ( i = 0; i < C.size( ); i++ ) {
      C[i] = i + 10;
      D[i] = i + 10.123;
   }
   cout << C << endl;
   cout << D << endl;
   return 0;
}