#include <iostream>
#ifndef SENECA_DYNARRAY
#define SENECA_DYNARRAY
/*
to convert a class to a class template do the following:
1- Change the required type to a the placeholder of the tempate
2- Add the type of the temaplate as a signature to all the class name
   exceptions:
   a - do not add the the name of the class right after template
   b - do not add to the constructor names
   c = do not add to the destructor name

*/

/* tempate requirements
T must have no-arg constructor
T must be able to be copy assigned


*/

namespace seneca {
   template<typename T>
   class DynArray {
      T* m_data;
      size_t m_size;
      DynArray<T>& resize( size_t newsize );
   public:
      DynArray( size_t size = 1 );
      DynArray( const DynArray<T>& cp );
      DynArray<T>& operator=( const DynArray<T>& cp );
      size_t size( )const;
      T& operator[]( size_t index );
      const T& operator[]( size_t index )const;
      virtual ~DynArray( );
      std::ostream& display( std::ostream& ostr = std::cout )const;
   };

   template<typename T>
   std::ostream& operator<<( std::ostream& ostr, const DynArray<T>& Ro );

   
   template <typename T>
   DynArray<T>::DynArray( size_t size ) {
      if ( size <= 0 ) size = 1;
      m_data = new T[m_size = size];  // T must have no-arg constructor
   }

   template <typename T> 
   DynArray<T>::DynArray( const DynArray<T>& cp ) {
      m_data = new T[m_size = cp.m_size]; 
      for ( size_t i = 0; i < m_size; i++ ) {
         m_data[i] = cp.m_data[i];
      }
   }



   template <typename T>
   DynArray<T>& DynArray<T>::operator=( const DynArray<T>& cp ) {
      if ( this != &cp ) {
         delete[] m_data;
         m_data = new T[m_size = cp.m_size];
         for ( size_t i = 0; i < m_size; i++ ) {
            m_data[i] = cp.m_data[i];
         }
      }
      return *this;
   }

   template <typename T>
   DynArray<T>::~DynArray( ) {
      delete[] m_data;
   }

   template <typename T>
   size_t DynArray<T>::size( ) const {
      return m_size;
   }

   template <typename T>
   T& DynArray<T>::operator[]( size_t index ) {
      if ( index >= m_size ) {
         resize( index + 1 );
      }
      return m_data[index];
   }

   template <typename T>
   const T& DynArray<T>::operator[]( size_t index )const {
      return m_data[index % m_size];
   }

   template <typename T>
   std::ostream& DynArray<T>::display( std::ostream& ostr )const {
      ostr << operator[]( 0 );
      for ( size_t i = 1; i < size( ); i++ ) {
         ostr << ", " << (*this)[i];
      }
      return ostr;
   }


   template <typename T>
   DynArray<T>& DynArray<T>::resize( size_t newsize ) {
      T* temp = new T[newsize];
      for ( size_t i = 0; i < m_size && i < newsize; i++ ) {
         temp[i] = m_data[i];
      }
      m_size = newsize;
      delete[] m_data;
      m_data = temp;
      return *this;
   }

   template <typename T>
   std::ostream& operator<<( std::ostream& ostr, const DynArray<T>& Ro ) {
      return Ro.display( ostr );
   }


}

#endif