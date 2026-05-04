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
   Name( const Name& N ) {
      if ( N.m_value ) {
         Cstr::alocpy( m_value, N.m_value );
      }
   }
   Name& operator=( const Name& N ) {
      if ( this != &N ) {
         Cstr::alocpy( m_value, N.m_value );
      }
      return *this;
   }
   Name( Name&& N ) { // move constructor
      if ( N.m_value ) {
         m_value = N.m_value;
         N.m_value = nullptr;
      }
   }
   //Name( Name&& N ) { // move constructor
   //   operator=( move(N) );
   //}

   Name& operator=( Name&& N ) { // move assignment
      if ( this != &N ) {
         delete[] m_value;
         m_value = N.m_value;
         N.m_value = nullptr;
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
void WhichValue( int& lv ) {
   cout << "lv: " << lv << endl;
}

void WhichValue( int&& rv ) {
   cout << "rv: " << rv << endl;
}

void WhichValue( Name& lv ) {
   cout << "lv: " << lv << endl;
}
void WhichValue( Name&& rv ) {
   cout << "rv: " << rv << endl;
}


int main( ) {
   int i = 10;
   Name N = "Fred";
   Name F = "Jack";

   cout << "N: " << N << " F:" << F << endl;

   N = move( F );

   cout << "N: " << N << " F:" << F << endl;

   return 0;
}