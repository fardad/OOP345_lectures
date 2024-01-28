#include <iostream>
#include "CStr.h"
#include "Tracer.h"
using namespace std;
using namespace sdds;
class Name {
private:
   char* m_value{};
public:
   Name( const char* value = nullptr ) {
      if ( value ) {
         CStr::allocNcpy( m_value, value );
      }
      tracer << "Create " << m_value << nl;
   }
   Name( const Name& N ) {
      tracer << "Copy " << N.m_value << nl << "  using: ";
      operator=( N );
   }
   Name& operator=( const Name& N ) {
      if ( this != &N ) {
         tracer << "Assign " << m_value << " to " << N.m_value << nl;
         delete[] m_value;
         CStr::allocNcpy( m_value, N.m_value );
      }
      return *this;
   }
   ~Name( ) {
      tracer << "Remove " << m_value << " from memory" << nl;
      delete[] m_value;
   }
   ostream& print( ostream& os = cout )const {
      return os << (m_value ? m_value : "(Nullstr)");
   }
   istream& read( istream& is = cin ) {
      delete[] m_value;
      m_value = CStr::read( is );
      return is;
   }
};

ostream& operator<< ( ostream& os, const Name& N ) {
   return N.print( os );
}
istream& operator>> ( istream& is, Name& N ) {
   return N.read( is );
}


int main( ) {
   cout << "Good morning oop345NBB!" << endl;
   tracer.trace( false );
   Name A;
   cout << "Name: ";
   tracer << "cin >> A;" << nl;
   cin >> A;
   cout << "Hello " << A << endl;
   tracer << "Name B = A;" << nl;
   Name B = A;
   cout << "B: " << B << endl;
   tracer << "A = \"Jack\";" << nl;
   A = "Jack";
   cout << "A: " << A << endl;
   tracer << "A = B;" << nl;
   A = B;
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   return 0;
}