#include <iostream>
using namespace std;
void print( int* ar, int size ) {
   for ( int i = 0; i < size; i++ ) {
      if ( i ) cout << ", ";
      cout << ar[i];
   }
   cout << endl;
}
void advance( int*& p ) {
   p++;
}

void advance( int** ptr ) {
   (*ptr)++;
}

void addOne( int* ptr ) {
   (*ptr)++;
}

int main( ) {
   int a[5]{ 100, 200,300,400,500 };
   int* ptr = a;
   int I = 10;
   print( ptr, 5 );
   ptr++;
   cout << *ptr << endl;
   advance( ptr );  // void advance( int*& p = ptr) 
   cout << *ptr << endl;
   addOne( &I ); // void addOne( int* ptr = &I )

   advance( &ptr );
   cout << (*ptr) << endl;
   return 0;
}