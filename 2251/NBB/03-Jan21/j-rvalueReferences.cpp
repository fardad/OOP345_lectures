#include <iostream>
#include "cstr.h"
using namespace std;
class Name {
private:
   char* m_value{};//  = nullptr; // could have had it here
public:
   Name( const char* value = nullptr ) {
      if ( value ) {
         Cstr::alocpy( m_value, value );
      }
   }
   Name& operator=( const Name& N ) {
      if ( this != &N ) {
         Cstr::alocpy( m_value, N.m_value );
      }
      return *this;
   }
   ostream& print( ostream& os )const {
      os << (m_value ? m_value : "");
      return os;
   }
   virtual ~Name( ) {
      delete[] m_value;
   }
};
ostream& operator<< ( ostream& os, const Name& N ) {
   return N.print( os );
}

void whichValue( int& a ) {
   cout << "lvalue: " << a << endl;
}

void whichValue( int&& a ) {
   cout << "rvalue: " << a << endl;
}


void whichValue( Name& a ) {
   cout << "lvalue: " << a << endl;
}

void whichValue( Name&& a ) {
   cout << "rvalue: " << a << endl;
}


int main( ) {
   int a = 10;
   Name F( "Fred" );
   whichValue( a );
   whichValue( 100 );
   whichValue( F );
   whichValue( move(F) );
   whichValue( Name( "John" ) );
   whichValue( "Jake" );
   return 0;
}
