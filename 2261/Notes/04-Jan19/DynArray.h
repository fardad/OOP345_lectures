#ifndef SENECA_DYNARRAY
#define SENECA_DYNARRAY
#include <iostream>
/*
to convert a class to a class template do the following:
1- Change the focused type to a the placeholder of the tempate
2- Add the type of the temaplate as a signature to all the class name
   exceptions:
   a - do not add the the name of the class right after template
   b - do not add to the constructor names
   c = do not add to the destructor name

*/

namespace seneca {
   template<typename T>
   class DynArray {
      T* m_data;
      int m_size;
      void resize( int newsize );
   public:
      DynArray( int size = 1 );
      DynArray( const DynArray<T>& cp );
      DynArray<T>& operator=( const DynArray<T>& cp );
      int size( )const;
      T& operator[]( int index );
      const T& operator[]( int index )const;
      virtual ~DynArray( );
      std::ostream& display( std::ostream& ostr = std::cout )const;

   };

   template<typename T>
   std::ostream& operator<<( std::ostream& ostr, const DynArray<T>& Ro );

   template<typename T>
   DynArray<T>::DynArray( int size ) {
      if ( size <= 0 ) size = 1;
      m_data = new T[m_size = size] { };
   }
   template<typename T>
   DynArray<T>::DynArray( const DynArray<T>& Other ) {
      m_data = new T[m_size = Other.m_size];
      for ( int i = 0; i < m_size; i++ ) {
         m_data[i] = Other.m_data[i];
      }
   }
   template<typename T>
   DynArray<T>& DynArray<T>::operator=( const DynArray<T>& Other ) {
      if ( this != &Other ) {
         delete[] m_data;
         m_data = new T[m_size = Other.m_size];
         for ( int i = 0; i < m_size; i++ ) {
            m_data[i] = Other.m_data[i];
         }
      }
      return *this;
   }
   template<typename T>
   DynArray<T>::~DynArray( ) {
      delete[] m_data;
   }
   template<typename T>
   int DynArray<T>::size( ) const {
      return m_size;
   }
   template<typename T>
   T& DynArray<T>::operator[]( int index ) {
      if ( index < 0 ) index = 0;
      if ( index >= m_size ) {
         resize( index + 1 );
      }
      return m_data[index];
   }
   template<typename T>
   const T& DynArray<T>::operator[]( int index )const {
      if ( index < 0 ) index = 0;
      return m_data[index % m_size];
   }

   template<typename T>
   std::ostream& DynArray<T>::display( std::ostream& ostr )const {
      ostr << operator[]( 0 );
      for ( int i = 1; i < size( ); i++ ) {
         ostr << "," << (*this)[i];
      }
      return ostr;
   }

   template<typename T>
   void DynArray<T>::resize( int newsize ) {
      T* temp = new T[newsize];
      for ( int i = 0; i < m_size && i < newsize; i++ ) {
         temp[i] = m_data[i];
      }
      m_size = newsize;
      delete[] m_data;
      m_data = temp;
   }
   template<typename T>
   std::ostream& operator<<( std::ostream& ostr, const DynArray<T>& Ro ) {
      return Ro.display( ostr );
   }

}
#endif // !SENECA_DYNARRAY

