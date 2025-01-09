#include "IntArray.h"
namespace seneca {
   IntArray::IntArray( size_t size ) {
      if ( size == 0 ) size = 1;
      m_data = new int[m_size = size];
   }
   IntArray::IntArray( const IntArray& cp ) {
      m_data = new int[m_size = cp.m_size];
      for ( size_t i = 0; i < m_size; i++ ) {
         m_data[i] = cp.m_data[i];
      }
   }
   IntArray& IntArray::operator=( const IntArray& cp ) {
      if ( this != &cp ) {
         delete[] m_data;
         m_data = new int[m_size = cp.m_size];
         for ( size_t i = 0; i < m_size; i++ ) {
            m_data[i] = cp.m_data[i];
         }
      }
      return *this;
   }

   size_t IntArray::size( ) const {
      return m_size;
   }

   int& IntArray::operator[]( size_t index ) {
      if ( index >= m_size ) {
         resize( index + 1 );
      }
      return m_data[index];
   }

   const int& IntArray::operator[]( int index ) const {
      return m_data[index % m_size]; // shoot in the foot
  /*    static int garbage{};
      int* ret = &garbage;
      if ( index < m_size ) {
         ret = &m_data[index];
      }
      return *ret;*/
   }

   IntArray::~IntArray( ) {
      delete[] m_data;
   }

   std::ostream& IntArray::display( std::ostream& ostr ) const {
      for ( size_t i = 0; i < m_size; i++ ) {
         if ( i ) ostr << ", ";
         ostr << m_data[i];
      }
   }
   std::ostream& operator<<( std::ostream& ostr, const IntArray& Ro ) {
      return Ro.display( ostr );
   }


   void IntArray::resize( size_t newsize ) {
      int* temp = new int[newsize];
      for ( size_t i = 0; i < m_size && i < newsize; i++ ) {
         temp[i] = m_data[i];
      }
      m_size = newsize;
      delete[] m_data;
      m_data = temp;
   }

}