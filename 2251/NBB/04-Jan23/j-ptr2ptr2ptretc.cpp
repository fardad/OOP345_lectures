#include <iostream>
using namespace std;

void change( int**** p ) {
   (*p)++;
}


void change( int*** p ) {
   (*p) += 2;
   change( &p );
}

void gotoNext( int** p ) {
   (*p)++;
   change( &p );

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

   gotoNext( &p );

   cout << *p << endl; // so this prints 30;

   return 0;
}
