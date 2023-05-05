#pragma once
#ifndef VALIDATED_H__
#define VALIDATED_H__
#include <iostream>
#include <string>



/* Template info :
   Type must be compatible with istream extraction operator
   Type must be compatible with ostream insertion operator
   Type must be able de be defaulted
   Type must have rule of five
*/



template <typename Type>
class Validated { // class name after template does not get the Type
   Type m_value{};
   std::string m_message{};
   bool (*m_valid)(Type value, std::string& messageOut);
   auto isValid()const->bool {
      return m_message == "";
   }
public:
   Validated(Type value, bool (*isValid)(Type, std::string&) = nullptr);
   Validated(bool (*isValid)(Type, std::string&) = nullptr);
   auto get(std::istream& istr)->std::istream&;
   auto put(std::ostream& ostr) const->std::ostream&;
   auto set(bool (*isValid)(Type, std::string&)) -> void;
   auto operator=(const Type& value)->Validated<Type>& {
      if (m_valid == nullptr || m_valid(value, m_message)) {
         m_value = value;
      }
      return *this;
   }
   void operator()(int num) {
      for (int i = 0; i < num; i++) {
         cout << *this << " ";
      }
      cout << endl;
   }
   void operator()(int num, char ch) {
      for (int i = 0; i < num; i++) {
         cout << *this << ch;
      }
      cout << endl;
   }
};


template <typename Type>
class ValidatedArray {
   Validated<Type>* m_Vvalues{};
   size_t m_size{};

   ValidatedArray<Type>& resize(size_t newsize) {
      Validated<Type>* temp = new Validated<Type>[newsize];
      for (size_t i = 0; i < m_size && i < newsize; i++) {
         temp[i] = m_Vvalues[i];
      }
      delete[] m_Vvalues;
      m_Vvalues = temp;
      m_size = newsize;
      return *this;
   }

public:
   ValidatedArray() {  
   }
   Validated<Type>& operator[](size_t index) {
      if (index >= m_size) {
         resize(index + 1);
      }
      return m_Vvalues[index];
   }
   const Validated<Type>& operator[](size_t index)const {
      return m_Vvalues[index%m_size];
   }
   ValidatedArray(const ValidatedArray<Type>&) = delete;
   ValidatedArray(const ValidatedArray<Type>&&) = delete;
   ValidatedArray& operator=(const ValidatedArray<Type>&) = delete;
   ValidatedArray& operator=(const ValidatedArray<Type>&&) = delete;
   ~ValidatedArray() {
      delete[] m_Vvalues;
   }
};



template <typename Type>
Validated<Type>::Validated(Type value, bool(*isValid)(Type, std::string&)) {
   m_value = value;
   m_valid = isValid;
}
template <typename Type>
Validated<Type>::Validated(bool(*isValid)(Type, std::string&)) {
   m_valid = isValid;
}
template <typename Type>
auto Validated<Type>::get(std::istream& istr)->std::istream& {
   bool done = false;
   do {
      if (istr >> m_value) {  
         if (m_valid != nullptr) {
            done = m_valid(m_value, m_message);
         }
         else {
            done = true;
         }
      }
      else {
         m_message = "Invalid Integer, try again: ";
         istr.clear();
      }
      istr.ignore(1000, '\n');
   } while (!done && cout << m_message);
   return istr;
}
template <typename Type>
auto Validated<Type>::put(std::ostream& ostr) const->std::ostream& {
   return ostr << m_value; // DV
}
template <typename Type>
auto Validated<Type>::set(bool(*isValid)(Type, std::string&))->void {
   m_valid = isValid;
}

template <typename Type>
auto operator<<(std::ostream& ostr, const Validated<Type>& I)->std::ostream& {
   return I.put(ostr);
}
template <typename Type>
auto operator>>(std::istream& istr, Validated<Type>& I)->std::istream& {
   return I.get(istr);
}
#endif