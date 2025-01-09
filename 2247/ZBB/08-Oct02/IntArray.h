#pragma once
#include <iostream>
#ifndef SENECA_INTARRAY
#define SENECA_INTARRAY
namespace seneca {
   class IntArray {
      int* m_data{};
      size_t m_size{};
      IntArray& resize( size_t newSize );
   public:
      IntArray( size_t size = 1 );
      IntArray( const IntArray& cp );
      IntArray& operator=( const IntArray& cp );
      size_t size( )const;
      int& operator[]( size_t index );
      const int& operator[]( size_t index )const;
      virtual ~IntArray( );
      std::ostream& display( std::ostream& ostr = std::cout )const;
   };
   std::ostream& operator<<( std::ostream& ostr, const IntArray& Ro );

}
#endif
