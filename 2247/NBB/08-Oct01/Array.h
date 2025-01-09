#pragma once
#include <iostream>
#ifndef SENECA_ARRAY
#define SENECA_ARRAY
/*
add the type to all the class names except:
1- name of the class right after template
2- constructor names
3- destructor name

*/

namespace seneca {
   template<typename type>
   class Array {
      type* m_data{};
      size_t m_size{};
      void resize( size_t newsize );
   public:
      Array( size_t size = 1 );
      Array( const Array<type>& cp );
      Array<type>& operator=( const Array<type>& cp );
      size_t size( )const;
      type& operator[]( size_t index );
      const type& operator[]( size_t index )const;
      virtual ~Array( );
      std::ostream& display( std::ostream& ostr = std::cout )const;

   };

   template<typename heehoo>
   std::ostream& operator<<( std::ostream& ostr, const Array<heehoo>& Ro );


   template <typename type>
   void Array<type>::resize( size_t newsize ) {
      type* temp = new type[newsize];// type must have no-arg constructor
      for ( size_t i = 0; i < m_size && i < newsize; i++ ) {
         temp[i] = m_data[i];  // copy assignment
      }
      m_size = newsize;
      delete[] m_data;
      m_data = temp;
   }
   template <typename type>
   Array<type>::Array( size_t size ) {
      if ( size == 0 ) size = 1;
      m_data = new type[m_size = size];
   }

   template <typename type>
   Array<type>::Array( const Array<type>& cp ) {
      m_data = new type[m_size = cp.m_size];
      for ( size_t i = 0; i < m_size; i++ ) {
         m_data[i] = cp.m_data[i];
      }
   }

   template <typename type>
   Array<type>& Array<type>::operator=( const Array<type>& cp ) {
      if ( this != &cp ) {
         delete[] m_data;
         m_data = new type[m_size = cp.m_size];
         for ( size_t i = 0; i < m_size; i++ ) {
            m_data[i] = cp.m_data[i];
         }
      }
      return *this;
   }

   template <typename type>
   size_t Array<type>::size( ) const {
      return m_size;
   }

   template <typename type>
   type& Array<type>::operator[]( size_t index ) {
      if ( index >= m_size ) {
         resize( index + 1 );
      }
      return m_data[index];
   }

   template <typename type>
   const type& Array<type>::operator[]( size_t index ) const {
      return m_data[index % m_size]; // shoot in the foot
      /*    static type garbage{};
          type* ret = &garbage;
          if ( index < m_size ) {
             ret = &m_data[index];
          }
          return *ret;*/
   }

   template <typename type>
   Array<type>::~Array( ) {
      delete[] m_data;
   }


   template <typename type>
   std::ostream& Array<type>::display( std::ostream& ostr ) const {
      for ( size_t i = 0; i < m_size; i++ ) {
         if ( i ) ostr << ", ";
         ostr << m_data[i]; // type must be insterable into ostrem
      }
      return ostr;
   }

   template <typename type>
   std::ostream& operator<<( std::ostream& ostr, const Array<type>& Ro ) {
      return Ro.display( ostr );
   }







}



#endif