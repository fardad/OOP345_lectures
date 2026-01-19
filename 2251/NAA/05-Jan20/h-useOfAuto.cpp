#include <iostream>
using namespace std;
class {
   bool m_trace{ };
public:
   auto& trace(bool onOff ) {
      m_trace = onOff;
      return *this;
   }
   auto& operator<<( const char* message ) {
      if ( m_trace ) {
         cout << (message ? message : "");
      }
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

} tracer;

int main( ) {
   int a[]{ 10, 20, 30, 40, 50, 60, 70 , 80 , 90 , 100 };
   int* p = a;
   tracer.trace( true );
   tracer << "value of P is: " << *p << "\n";
   cout << *p << endl;
   return 0;
}