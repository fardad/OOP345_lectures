#pragma once
#ifndef SDDS_DYNARRAY_H
#define SDDS_DYNARRAY_H
#include <iostream>
namespace sdds {
   // 1 change all the types of interest to the template type
   // 2 add the tag of template <type, Tsize> to all the class name
   // except, the name of the class right after the template
   // all names of constructor definitions
   // the name of destructor
   template <typename type, int Tsize=1>
   class DynArray {
      type* m_data;
      int m_size;
      void resize(int newsize);
      static int X;
   public:
      DynArray(int size = Tsize);
      DynArray(const DynArray<type, Tsize>& cp);
      DynArray<type, Tsize>& operator=(const DynArray<type, Tsize>& cp);
      int size()const;
      type& operator[](int index);
      const type& operator[](int index)const;
      virtual ~DynArray();
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };

   template<typename type, int Tsize>
   static int DynArray<type, Tsize>::X = 0;


   template <typename type, int Tsize=1>
   std::ostream& operator<<(std::ostream& ostr, const DynArray<type, Tsize>& Ro);

   template <typename type, int Tsize>
   DynArray<type, Tsize>::DynArray(int size) {
      if (size <= 0) size = 1;
      m_data = new type[m_size = size];  // default constr
   }
   template <typename type, int Tsize>
   DynArray<type, Tsize>::DynArray(const DynArray<type, Tsize>& cp) {
      m_data = new type[m_size = cp.m_size];
      for (int i = 0; i < m_size; i++) {
         m_data[i] = cp.m_data[i];   // copy assign
      }
   }
   template <typename type, int Tsize>
   DynArray<type, Tsize>& DynArray<type, Tsize>::operator=(const DynArray<type, Tsize>& cp) {
      if (this != &cp) {
         delete[] m_data;
         m_data = new type[m_size = cp.m_size];
         for (int i = 0; i < m_size; i++) {
            m_data[i] = cp.m_data[i];
         }
      }
      return *this;
   }
   template <typename type, int Tsize>
   DynArray<type, Tsize>::~DynArray() {
      delete[] m_data;
   }


   template <typename type, int Tsize>
   int DynArray<type, Tsize>::size() const {
      return m_size;
   }


   template <typename type, int Tsize>
   type& DynArray<type, Tsize>::operator[](int index) {
      if (index < 0) index = 0;
      if (index >= m_size) {
         resize(index + 1);
      }
      return m_data[index];
   }

   template <typename type, int Tsize>
   const type& DynArray<type, Tsize>::operator[](int index)const {
      if (index < 0) index = 0;
      return m_data[index % m_size];
   }

   template <typename type, int Tsize>
   std::ostream& DynArray<type, Tsize>::display(std::ostream& ostr)const {
      ostr << operator[](0);
      for (int i = 1; i < size(); i++) {
         ostr << "," << (*this)[i];
      }
      return ostr;
   }


   template <typename type, int Tsize>
   void DynArray<type, Tsize>::resize(int newsize) {
      type* temp = new type[newsize];
      for (int i = 0; i < m_size && i < newsize; i++) {
         temp[i] = m_data[i];
      }
      m_size = newsize;
      delete[] m_data;
      m_data = temp;
   }


   template <typename type, int Tsize>
   std::ostream& operator<<(std::ostream& ostr, const DynArray<type, Tsize>& Ro) {
      return Ro.display(ostr);
   }


}
#endif // !SDDS_DYNARRAY_H
