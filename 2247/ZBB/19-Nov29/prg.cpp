#include <iostream>
using namespace std;
void processArray( int ( *arr )[20] ) {
   for ( int i = 0; i < 20; i++ ) {
      std::cout << (*arr)[i] << " ";
   }
}

int main( ) {
   int ( *p )[20] = (int( * )[20]) new int[20];
   (*p)[0] = 42;
   processArray( p );  // Pass the pointer to the array
   delete[] p;
   return 0;
}
