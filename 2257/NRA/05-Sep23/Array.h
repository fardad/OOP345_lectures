#pragma once
#ifndef SENECA_ARRAY_H
#define SENECA_ARRAY_H
#include <iostream>

/* To conver a class to a class template you do the following:
   1- add the template statement to all scopes of the code
   2- change the focus (what the class is supposed to template> to the template type
   3- add the type of the template to all the template class name EXCEPT:
      I- The name of the class right after the template statement
      II- The constructor
      III= the destructor
*/



namespace seneca {

   /// <summary>
   /// creates and arrary of types
   /// type must support default construction
   /// type must support assignment
   /// type must be insertable into ostream
   /// </summary>
   /// <typeparam name="type"></typeparam>
   template <typename type>
   class Array {
      type* m_data;
      size_t m_size;
      void resize(size_t newsize);
   public:
      Array(size_t size = 1);
      Array(const Array<type>& cp);
      Array(Array<type>&& mv) noexcept;
      Array<type>& operator=(const Array<type>& cp);
      Array<type>& operator=(Array<type>&& mv) noexcept;

      size_t size()const;

      type& operator[](size_t index);
      const type& operator[](size_t index)const;
      virtual ~Array();
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };

   template <typename type>
   std::ostream& operator<<(std::ostream& ostr, const Array<type>& Ro);

   template <typename type>
   Array<type>::Array(size_t size) {
      if (size == 0) size = 1;
      m_data = new type[m_size = size]{};
   }

   template <typename type>
   Array<type>::Array(const Array<type>& cp) {
      m_data = new type[m_size = cp.m_size]{};
      for (size_t i = 0; i < m_size; i++) {
         m_data[i] = cp.m_data[i];
      }
   }

   template <typename type>
   Array<type>::Array(Array<type>&& mv) noexcept {
      m_size = mv.m_size;
      m_data = mv.m_data;
      mv.m_data = new type[1]{};
      mv.m_size = 1;
   }

   template <typename type>
   Array<type>& Array<type>::operator=(const Array<type>& cp) {
      if (this != &cp) {
         delete[] m_data;
         m_data = new type[m_size = cp.m_size]{};
         for (size_t i = 0; i < m_size; i++) {
            m_data[i] = cp.m_data[i];
         }
      }
      return *this;
   }

   template <typename type>
   Array<type>& Array<type>::operator=(Array<type>&& mv) noexcept {
      if (this != &mv) {
         // delete current data
         delete[] m_data;
         // take ownership of other
         m_size = mv.m_size;
         m_data = mv.m_data;
         // set other data to empty
         mv.m_data = new type[1]{};
         mv.m_size = 1;
      }
      return *this;
   }

   template <typename type>
   Array<type>::~Array() {
      delete[] m_data;
   }

   template <typename type>
   size_t Array<type>::size() const {
      return m_size;
   }

   template <typename type>
   type& Array<type>::operator[](size_t index) {
      if (index >= m_size) {
         resize(index + 1);
      }
      return m_data[index];
   }

   template <typename type>
   const type& Array<type>::operator[](size_t index)const {
      return m_data[index % m_size];
   }

   template <typename type>
   std::ostream& Array<type>::display(std::ostream& ostr)const {
      ostr << operator[](0);
      for (size_t i = 1; i < size(); i++) {
         ostr << "," << (*this)[i];
      }
      return ostr;
   }

   template <typename type>
   void Array<type>::resize(size_t newsize) {
      type* temp = new type[newsize]{};
      for (size_t i = 0; i < m_size && i < newsize; i++) {
         temp[i] = m_data[i];
      }
      m_size = newsize;
      delete[] m_data;
      m_data = temp;
   }

   template <typename type>
   std::ostream& operator<<(std::ostream& ostr, const Array<type>& Ro) {
      return Ro.display(ostr);
   }
}
#endif // !SENECA_ARRAY_H

