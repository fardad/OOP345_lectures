#ifndef SDDS_DYNARRAY
#define SDDS_DYNARRAY
#include <iostream>
namespace sdds {
   /*
    1- change the T of the focus of the class to templated T
    2- add the signature of the template to all the Class names other than:
       a- the Name of class coming right after the temaplate
       b- Constructor names
       c- Destructor name
   */
template <typename T>
  class DynArray {
      T* m_data;
      size_t m_size;
      void resize(size_t newsize);
   public:
      DynArray(size_t size = 1);
      DynArray(const DynArray<T>& cp);
      DynArray<T>& operator=(const DynArray<T>& cp);
      size_t size()const;
      T& operator[](size_t index);
      const T& operator[](size_t index)const;
      virtual ~DynArray();
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };

   template <typename T>
   std::ostream& operator<<(std::ostream& ostr, const DynArray<T>& Ro);

   template <typename T>
   DynArray<T>::DynArray(size_t size) {
      if(size == 0) size = 1;
      m_data = new T[m_size = size];
   }


   template <typename T>
   DynArray<T>::DynArray(const DynArray<T>& cp) {
      m_data = new T[m_size = cp.m_size];
      for(size_t i = 0; i < m_size; i++) {
         m_data[i] = cp.m_data[i];                                      // copy assignment 
      }
   }

   template <typename T>
   DynArray<T>& DynArray<T>::operator=(const DynArray<T>& cp) {
      if(this != &cp) {
         delete[] m_data;
         m_data = new T[m_size = cp.m_size];
         for(size_t i = 0; i < m_size; i++) {
            m_data[i] = cp.m_data[i];
         }
      }
      return *this;
   }

   
   template <typename T>
   DynArray<T>::~DynArray() {
      delete[] m_data;
   }

   template <typename T>
   size_t DynArray<T>::size() const {
      return m_size;
   }

   template <typename T>
   T& DynArray<T>::operator[](size_t index) {
      if(index >= m_size) {
         resize(index + 1);
      }
      return m_data[index];
   }

   template <typename T>
   const T& DynArray<T>::operator[](size_t index)const {
      return m_data[index % m_size];
   }


   template <typename T>
   std::ostream& DynArray<T>::display(std::ostream& ostr)const {
      ostr << operator[](0);                                         //  T must be insertable into ostream using << operator
      for(size_t i = 1; i < size(); i++) {
         ostr << ", " << (*this)[i];
      }
      return ostr;
   }

   template <typename T>
   void DynArray<T>::resize(size_t newsize) {
      if(newsize == 0) newsize = 1;
      T* newArray = new T[newsize];                                 // no arg constructor or default constructor
      for(size_t i = 0; i < m_size && i < newsize; i++) {
         newArray[i] = m_data[i];
      }
      m_size = newsize;
      delete[] m_data;
      delete[] m_data;
      m_data = newArray;
   }


   template <typename T>
   std::ostream& operator<<(std::ostream& ostr, const DynArray<T>& Ro) {
      return Ro.display(ostr);
   }



}

#endif // !SDDS_DYNARRAY