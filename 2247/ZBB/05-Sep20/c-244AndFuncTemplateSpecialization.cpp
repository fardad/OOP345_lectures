#include <iostream>
using namespace std;
//template <typename T>
template <class T>
void swap( T* a, T* b ) {
   T c;
   c = *a;
   *a = *b;
   *b = c;
}
// specialized template only for swaping ints.
template <>
void swap<int>( int* a, int* b ) {
   *a = *a ^ *b;
   *b = *a ^ *b;
   *a = *a ^ *b;
}
int main( ) {

   double a = 2.3;
   double b = 4.5;
   int i = 4, j = 10;
   char   d = 'A';
   char   e = 'B';
   swap( &a, &b );
   std::cout << "Swapped values are " <<
      a << " and " << b << std::endl;
   swap( &d, &e );
   std::cout << "Swapped values are " <<
      d << " and " << e << std::endl;
   swap( &i, &j );
   return 0;
}