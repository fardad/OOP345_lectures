#include <iostream>
#include "CStr.h"
#include "Tracer.h"
using namespace std;
using namespace seneca;
class Name {
private:
   char* m_value{};
public:
   Name( const char* value = nullptr ) {
      if ( value ) {
         Cstr::alocpy( m_value, value );
      }
      tracer << "Create " << m_value << nl;
   }
   Name( const Name& N ) {
      tracer << "Copy " << N.m_value << nl << "  using: ";
      operator=( N );
   }
   Name( Name&& N ) {
      operator=( move( N ) );
   }
   Name& operator=( const Name& N ) {
      if ( this != &N ) {
         tracer << "Assign " << m_value << " to " << N.m_value << nl;
         delete[] m_value;
         Cstr::alocpy( m_value, N.m_value );
      }
      return *this;
   }
   Name& operator=( Name&& N ) {
      if ( this != &N ) {
         tracer << " Move assign " << N.m_value << " into " << m_value << " by assignment" << nl;
         delete[] m_value;
         m_value = N.m_value;
         N.m_value = nullptr;
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
      m_value = Cstr::read( is );
      return is;
   }
};

ostream& operator<< ( ostream& os, const Name& N ) {
   return N.print( os );
}
istream& operator>> ( istream& is, Name& N ) {
   return N.read( is );
}
Name getName( ) {
   Name N;
   cout << "Enter a name: ";
   cin >> N;
   return N;
}


int main( ) {
   cout << "OOP345 NBB - Jan 28 " << endl;
   tracer.trace( );
   Name A = "Fred";
   Name B = A;
   Name C;
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   cout << "C: " << C << endl;
   tracer << " C = move(A);" << nl;
   C = move( A );

   A = ref( B ); // no use!!! it is a ref already
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   cout << "C: " << C << endl;
   tracer << "Name D = getName();" << nl;
   Name D = getName( ); // xvalue
   cout << "D: " << D << endl;
   tracer << "D = getName();" << nl;
   D = getName( );
   cout << "D: " << D << endl;
   tracer << "Name E = move(B);" << nl;
   Name E = move( B );
   cout << "E: " << E << endl;
   cout << "B: " << B << endl;
   C = "prvalue"; // pure right value
   // "prvalue" = C;  
   B = Name( "Xvalue" );
   Name( "Whatever" ) = C;
   cout << "B: " << B << endl;
   cout << "C: " << C << endl;
   cout << "Xval: " << (Name( "Xvalue/glvalue" ) = "some value") << endl;

   return 0;
}