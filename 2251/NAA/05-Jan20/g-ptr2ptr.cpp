#include <iostream>
using namespace std;


void goToNext( int** ptr ) {
   (*ptr)++;
}
void goToNext( int*& ptr ) {
   ptr++;
}

void addOne( int* p ) {
   (*p)++;
}

int main( ) {
   int a[]{ 10, 20, 30, 40, 50, 60, 70 , 80 , 90 , 100 };
   int* p = a;
   cout << *p << endl; // prints 10
   goToNext( &p );
   cout << *p << endl; // prints 20
   goToNext( p );
   cout << *p << endl; // prints 20
   int val = 20;
   addOne( &val );
   cout << val << endl;
   return 0;
}