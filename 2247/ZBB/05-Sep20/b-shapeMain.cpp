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
Shape* makeShape( ) {
   Shape* ret{};
   char ch{};
   double d{};
   cout << "(S)quare or (C)ircle?\n> ";
   cin >> ch;
   switch ( ch ) {
   case 's':
   case 'S':
      cout << "side length?\n> ";
      cin >> d;
      ret = new Square( d );
      break;
   case 'c':
   case 'C':
      cout << "raduis?\n> ";
      cin >> d;
      ret = new Circle( d );
   }
   return ret;
}
Shape* copy( const Shape& S ) {
   //   Shape* cp = new ? ? ? (S);
   Shape* cp = S.clone( );
   return cp;
}
int main( ) {
   cout << "05-Sep20 345ZAA" << endl;
   Shape* s1 = makeShape();
   Shape* s2 = makeShape( );
   Shape* copy = s1->clone( );
   displayShape( s1 );
   displayShape( s2 );
   compare( s1, s2 );
   cout << *copy << " and " << *s1 << " are ";
   if ( *copy == *s1 ) {
      cout << "obviously the same!!!" << endl;;
   }
   else {
      cout << "This will never happen!!!" << endl;
   }
   delete s1;
   delete s2;
   delete copy;
   return 0;
}