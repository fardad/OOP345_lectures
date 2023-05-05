#pragma once
#ifndef SDDS_DYNARRAY_H
#define SDDS_DYNARRAY_H
#include <iostream>
namespace sdds {
   // 1 change all the types of interest to the template type
   // 2 add the tag of template <type> to all the class name
   // except, the name of the class right after the template
   // all names of constructor definitions
   // the name of destructor
   template <typename type>
   class DynArray {
      type* m_data;
      int m_size;
      void resize(int newsize);
   public:
      DynArray(int size = 1);
      DynArray(const DynArray<type>& cp);
      DynArray<type>& operator=(const DynArray<type>& cp);
      int size()const;
      type& operator[](int index);
      const type& operator[](int index)const;
      virtual ~DynArray();
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };

   template <typename type>
   std::ostream& operator<<(std::ostream& ostr, const DynArray<type>& Ro);

   template <typename type>
   DynArray::DynArray(int size) {
      if (size <= 0) size = 1;
      m_data = new int[m_size = size];
   }
   DynArray::DynArray(const DynArray& cp) {
      m_data = new int[m_size = cp.m_size];
      for (int i = 0; i < m_size; i++) {
         m_data[i] = cp.m_data[i];
      }
   }
   DynArray& DynArray::operator=(const DynArray& cp) {
      if (this != &cp) {
         delete[] m_data;
         m_data = new int[m_size = cp.m_size];
         for (int i = 0; i < m_size; i++) {
            m_data[i] = cp.m_data[i];
         }
      }
      return *this;
   }
   DynArray::~DynArray() {
      delete[] m_data;
   }
   int DynArray::size() const {
      return m_size;
   }
   int& DynArray::operator[](int index) {
      if (index < 0) index = 0;
      if (index >= m_size) {
         resize(index + 1);
      }
      return m_data[index];
   }
   const int& DynArray::operator[](int index)const {
      if (index < 0) index = 0;
      return m_data[index % m_size];
   }

   std::ostream& DynArray::display(std::ostream& ostr)const {
      ostr << operator[](0);
      for (int i = 1; i < size(); i++) {
         ostr << "," << (*this)[i];
      }
      return ostr;
   }

   void DynArray::resize(int newsize) {
      int* temp = new int[newsize];
      for (int i = 0; i < m_size && i < newsize; i++) {
         temp[i] = m_data[i];
      }
      m_size = newsize;
      delete[] m_data;
      m_data = temp;
   }
   std::ostream& operator<<(std::ostream& ostr, const DynArray& Ro) {
      return Ro.display(ostr);
   }


}
#endif // !SDDS_DYNARRAY_H
