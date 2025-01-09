#include <iostream>
#include "Tracer.h"
using namespace std;
namespace seneca {
   Tracer& tracer = Tracer::instantiate( );
   Tracer& Tracer::instantiate( ) {
      static Tracer T;
      return T;
   }
   Tracer& Tracer::trace( bool value ) {
      m_trace = value;
      return *this;
   }
   const Tracer& Tracer::operator<<( const char* message )const {
      if ( m_trace ) cout << (message ? message : "(NULLstr)");
      return *this;
   }
   const Tracer& Tracer::operator<<( int val )const {
      if ( m_trace ) cout << val;
      return *this;
   }
   const Tracer& Tracer::operator<<( double val )const {
      if ( m_trace ) cout << val;
      return *this;
   }
   const Tracer& Tracer::operator<<( char ch )const {
      if ( m_trace ) cout << ch;
      return *this;
   }

}
