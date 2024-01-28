#pragma 
#ifndef SDDS_CSTR_H
#define SDDS_CSTR_H
#include <iostream>
namespace sdds {
   constexpr int ReadBufferSize = 50;
   class CStr {
   public:
      static void cpy( char* des, const char* src );
      static int len( const char* str );
      static void allocNcpy( char*& des, const char* src );
      static char* read( std::istream& is );
   };
}
#endif // !SDDS_CSTR_H

