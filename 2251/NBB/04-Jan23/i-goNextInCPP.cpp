#include <iostream>
using namespace std;

void gotoNext( int*& p ) {
   *p = 200;
   p++;
   *p = 300;
}

void prnArra( int ar[] ) {
   for ( int i = 0; i < 5; i++ ) cout << ar[i] << " ";
   cout << endl;
}

int main( ) {
   int ar[5]{ 10,20,30,40,50 };
   int* p = ar;
   p++;
   cout << *p << endl;
   prnArra( ar );
   gotoNext( p );
   prnArra( ar );

   cout << *p << endl; // so this prints 30;

   return 0;
}