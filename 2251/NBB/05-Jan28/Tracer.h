#pragma once
#ifndef SENECA_TRACER_H
#define SENECA_TRACER_H
namespace seneca {
   constexpr char nl = '\n';
   class Tracer {
      bool m_trace{ };
      Tracer( ) = default;
   public:
      static Tracer& instantiate( );
      Tracer( const Tracer& ) = delete;
      Tracer& operator=( const Tracer& ) = delete;
      Tracer& trace( bool value = true );
      const Tracer& operator<<( const char* message )const;
      const Tracer& operator<<( int val )const;
      const Tracer& operator<<( double val )const;
      const Tracer& operator<<( char ch )const;

   };
   extern Tracer& tracer;
}

#endif // !SENECA_TRACER_H
