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
   Name F = "Fred", G, H;
   int a;

   a = 10;

   G = F;

   F = Name( "Jonh" );

   Name( "John" ) = G;
   
   H = "Henry";

   return 0;
}