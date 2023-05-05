#include <iostream>
#ifndef SDDS_DYNARRAY
#define SDDS_DYNARRAY
// 1 change all the types of interest to the template type
// 2 add the tag of template <type> to all the class name
   // except, the name of the class right after the template
   // except,all names of constructor definitions
   // except,the name of destructor
// do the same to all othe scopes envloved in the tempalge code
namespace sdds {
   template <typename type>
   class DynArray {
      type* m_data;
      int m_size;
      void resize(int newsize);
   public:
      DynArray(int size=1);
      DynArray(const DynArray<type>& cp);
      DynArray<type>& operator=(const DynArray<type>& cp);
      int size()const;
      type& operator[](int index);
      const type& operator[](int index)const;
      ~DynArray();
      std::ostream& display(std::ostream& ostr = std::cout)const;

   };
   template <typename type>
   std::ostream& operator<<(std::ostream& ostr, const DynArray<type>& Ro);


   template <typename type>
   DynArray<type>::DynArray(int size) {
      if (size <= 0) size = 1;
      m_data = new type[m_size = size];
   }

   template <typename type>
   DynArray<type>::DynArray(const DynArray<type>& cp) {
      m_data = new type[m_size = cp.m_size];
      for (int i = 0; i < m_size; i++) {
         //         m_data[i] = cp[i];
         m_data[i] = cp.m_data[i];
      }
   }

   template <typename type>
   DynArray<type>& DynArray<type>::operator=(const DynArray<type>& cp) {
      if (this != &cp) {
         delete[] m_data;
         m_data = new type[m_size = cp.m_size];
         for (int i = 0; i < m_size; i++) {
            //         m_data[i] = cp[i];
            m_data[i] = cp.m_data[i];
         }
      }
      return *this;
   }

   template <typename type>
   DynArray<type>::~DynArray() {
      delete[] m_data;
   }


   template <typename type>
   int DynArray<type>::size() const {
      return m_size;
   }

   template <typename type>
   type& DynArray<type>::operator[](int index) {
      if (index < 0) index = 0;
      if (index >= m_size) {
         resize(index + 1);
      }
      return m_data[index];
   }
   template <typename type>
   const type& DynArray<type>::operator[](int index)const {
      if (index < 0) index = 0;
      return m_data[index % m_size];
   }

   template <typename type>
   std::ostream& DynArray<type>::display(std::ostream& ostr)const {
      ostr << operator[](0);
      for (int i = 1; i < size(); i++) {
         ostr << "," << (*this)[i];
      }
      return ostr;
   }

   template <typename type>
   void DynArray<type>::resize(int newsize) {
      type* temp = new type[newsize];
      for (int i = 0; i < m_size && i < newsize; i++) {
         temp[i] = m_data[i];
      }
      m_size = newsize;
      delete[] m_data;
      m_data = temp;
   }

   template <typename type>
   std::ostream& operator<<(std::ostream& ostr, const DynArray<type>& Ro) {
      return Ro.display(ostr);
   }


}

#endif // SDDS_DYNARRAY



