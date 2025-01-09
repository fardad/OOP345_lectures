#include <iostream>
#ifndef SENECA_ARRAY
#define SENECA_ARRAY
/* To create a class template you must add the type of the template
* to all class names except:
* 1- The name of the class after the class keyword that comes after template
* 2 - the name of the constructors
* 3 - the name of the destructor
*/

namespace seneca {
   template <typename type>
   class Array {
      type* m_data{};
      size_t m_size{};
      Array<type>& resize( size_t newSize );
   public:
      Array( size_t size = 1 );
      Array( const Array& cp );
      Array<type>& operator=( const Array<type>& cp );
      size_t size( )const;
      type& operator[]( size_t index );
      operator const type* ()const;
      const type& operator[]( size_t index )const;
      virtual ~Array( );
      std::ostream& display( std::ostream& ostr = std::cout )const;
   };

   template <typename heehaw>
   std::ostream& operator<<( std::ostream& ostr, const Array<heehaw>& Ro );
   
   template<typename type>
   Array<type>::operator const type* ()const {
      return (const type*)m_data;
   }

   template<typename type>
   Array<type>& Array<type>::resize( size_t newSize ) {
      type* temp = new type[newSize] { }; // type requires no-arg constructor
      for ( size_t i = 0; i < m_size && i < newSize; i++ ) {
         temp[i] = m_data[i]; // type needs copy assignment
      }
      m_size = newSize;
      delete[] m_data;
      m_data = temp;
      return *this;
   }

   template<typename type>
   Array<type>::Array( size_t size ) {
      if ( size == 0 ) size = 1;
      m_data = new type [m_size = size] { };
   }
   template<typename type>
   Array<type>::Array( const Array<type>& cp ) {
      m_data = new type[m_size = cp.m_size];
      for ( size_t i = 0; i < m_size; m_data[i] = cp.m_data[i++] );
   }

   template<typename type>
   Array<type>& Array<type>::operator=( const Array<type>& cp ) {
      if ( this != &cp ) {
         delete[] m_data;
         m_data = new type[m_size = cp.m_size];
         for ( size_t i = 0; i < m_size; m_data[i] = cp.m_data[i++] );
      }
      return *this;
   }

   template<typename type>
   size_t Array<type>::size( ) const {
      return m_size;
   }

   template<typename type>
   type& Array<type>::operator[]( size_t index ) {
      if ( index >= m_size ) {
         resize( index + 1 );
      }
      return m_data[index];
   }

   template<typename type>
   const type& Array<type>::operator[]( size_t index ) const {
      return m_data[index % m_size];
      /*static type garbage{};
      type* element = &garbage;
      if ( index < m_size ) {
         element = &m_data[index];
      }
      return *element;*/
   }

   template<typename type>
   Array<type>::~Array( ) {
      delete[] m_data;
   }

   template<typename type>
   std::ostream& Array<type>::display( std::ostream& ostr ) const {
      for ( size_t i = 0; i < m_size; i++ ) {
         if ( i ) ostr << ", ";
         ostr << m_data[i];
      }
      return ostr;
   }
   template<typename type>
   std::ostream& operator<<( std::ostream& ostr, const Array<type>& Ro ) {
      return Ro.display( ostr );
   }
}
#endif 