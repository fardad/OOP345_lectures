#include <iostream>
using namespace std;
#include "Shape.h"
#include "Square.h"
#include "Circle.h"

void displayShape( const Shape* s ) {
   if ( s ) {
      cout << *s << endl;
   }
   else {
      cout << "nullptr" << endl;
   }
}
int main() {
   cout << "05-Sep19 NBB" << endl;
   Circle C( 10 );
   Square S( 10 );
   displayShape( &C );
   displayShape( &S );
   return 0;
}