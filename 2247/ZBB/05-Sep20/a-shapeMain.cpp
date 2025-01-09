#include <iostream>
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
using namespace std;
void displayShape( const Shape* sptr ) {
   if ( sptr ) {
      cout << *sptr << endl;
   }
   else {
      cout << "nullptr" << endl;
   }
}
void compare( const Shape* s1, const Shape* s2 ) {
   cout << *s1 << " and " << *s2 << " are ";
   if ( *s1 == *s2 ) {
      cout << "the Same" << endl;
   }
   else {
      cout << "different!" << endl;
   }
}
int main( ) {
   cout << "05-Sep20 345ZAA" << endl;
   Square S = 10;
   Square T = 10;
   Circle C = 10;
   Circle D = 11;

   cout << S << endl;
   displayShape( &S );
   displayShape( &C );
   compare( &S, &T );
   compare( &S, &C );
   compare( &C, &D );
   return 0;
}