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
//Shape* copy( const Shape& S ) { not possible
//   Shape* cp = new ????(S);
//   return cp
//}

int main() {
   cout << "06-Sep24" << endl;
   Shape* s1 = makeShape( );
   Shape* s2 = makeShape( );
   Shape* cp = s1->clone( );
   displayShape( s1 );
   displayShape( s2 );
   cout << "s1 and s2 are ";
   if ( *s1 == *s2 ) {
      cout << "same shapes" << endl;
   }
   else {
      cout << "different" << endl;
   }
   cout << "s1 and its clone are ";
   if ( *cp == *s1 ) {
      cout << "obviously the same" << endl;
   }
   else {
      cout << "impossible!!!" << endl;
   }
   delete s1;
   delete s2;
   delete cp;
   return 0;
}