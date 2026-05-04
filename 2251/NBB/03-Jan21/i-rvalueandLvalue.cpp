
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

int main( ) {
   double b;
   int i = 10;
   Name F = "Fred", G, H;

   F = Name( "John" );

   H = "Henry";

   b = double( i );

   Name( "What the heck?" ) = F;

   return 0;
}