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
   Name& operator=( Name&& N ) {
      if ( this != &N ) {
         delete[] m_value;
         m_value = N.m_value;
         N.m_value = nullptr;
      }
      return *this;
   }
   Name( Name&& N ) {
      m_value = N.m_value;
      N.m_value = nullptr;
   }
   Name& operator=( const Name& N ) {
      if ( this != &N ) {
         Cstr::alocpy( m_value, N.m_value );
      }
      return *this;
   }
   ostream& print( ostream& os )const {
      os << (m_value ? m_value : "NULLPTR");
      return os;
   }
   ~Name( ) {
      delete[] m_value;
   }
};
ostream& operator<< ( ostream& os, const Name& N ) {
   os << "lvalue: ";
   return N.print( os );
}

ostream& operator<< ( ostream& os, const Name&& N ) {
   os << "rvalue: ";
   return N.print( os );
}

void prnName( Name N ) {
   cout << N << endl;
}
int main( ) {
   Name A = "Jack"; // A("Jack");
   cout << A << endl;
   Name  B = move(A);    // B(Name&&N = A);
   Name C = Name( "John" );
   cout << "After Name Creations!" << endl;
   cout << A << endl;
   cout << B << endl;
   cout << C << endl;
   A = C;
   cout << A << endl;
   cout << C << endl;
   B = move(C); // and I don't need C anymore!!!!!!!
   cout << B << endl;
   cout << C << endl;
   cout << Name( "Iman" ) << endl;
   prnName( A );  // prnName (Name N = A);
   prnName( Name( "Wilson" ) ); // prnName(Name N = Name("Wilson"));
   return 0;
}