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
   //Name( const Name& N ) {
   //   if ( N.m_value ) {
   //      Cstr::alocpy( m_value, N.m_value );
   //   }
   //}

   Name( const Name& N ) {
      operator=( N );
   }

   /*Name( Name&& N ) {
      if ( N.m_value ) {
         m_value = N.m_value;
         N.m_value = nullptr;
      }
   }*/
   Name( Name&& N ) {
      operator=( move( N ) );
   }

   Name& operator=( const Name& N ) {
      if ( this != &N ) {
         Cstr::alocpy( m_value, N.m_value );
      }
      return *this;
   }

   Name& operator=(Name&& N ) {
      if ( this != &N ) {
         delete[] m_value;
         m_value = N.m_value;
         N.m_value = nullptr;
      }
      return *this;
   }
   ostream& print( ostream& os )const {
      os << (m_value ? m_value : "Empty");
      return os;
   }
   virtual ~Name( ) {
      delete[] m_value;
   }
};
ostream& operator<< ( ostream& os, const Name& N ) {
   return N.print( os );
}

Name MakeJane( ) {
   Name N = "Jane";
   return N;
}

void PrintName( Name N ) {
   cout << "Name is: " << N << endl;
}

int main( ) {
   Name F = "Fred"; // F("Fred") F{"Fred"}
   Name G = F ;
   cout << "F: " << F << endl;
   cout << "G: " << G << endl;
   Name M( move( F ) );
   cout << "F: " << F << endl;
   cout << "M: " << M << endl;

   G = "Jack";
   cout << "G: " << G << endl;

   PrintName( MakeJane( ) );

   PrintName( G );

   return 0;
}
