#include <iostream>
using namespace std;
class {
   bool m_trace{};
public:
   auto& trace( bool value = true ) {
      m_trace = value;
      return *this;
   }
   auto& operator<<( const char* message ) {
      if ( m_trace ) cout << (message ? message : "(NULLstr)");
      return *this;
   }
   auto& operator<<( int val ) {
      if ( m_trace ) cout << val;
      return *this;
   }
   auto& operator<<( double val ) {
      if ( m_trace ) cout << val;
      return *this;
   }
   auto& operator<<( char ch ) {
      if ( m_trace ) cout << ch;
      return *this;
   }
} tracer;


int main( ) {
   tracer.trace( true );
   int a, b = 10, c = 30;

   tracer << "adding b and c in a\n";
   a = b + c;
   tracer << "the value is " << a << "\n";


   return 0;
}