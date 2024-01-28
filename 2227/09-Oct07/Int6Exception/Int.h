#pragma once
#ifndef INT_H__
#define INT_H__
#include <iostream>
#include <string>
#include "Validation.h"
class Int {
   int m_value = 0;
   std::string m_message;
   Validation& m_valid;
public:
   Int(Validation& validationFunctor) :m_valid(validationFunctor) {}
   auto get(std::istream& istr)->std::istream& {
      if ((istr >> m_value).fail()) {
         istr.clear();
         throw badIntExp();
      }
      else {
         m_valid(m_value, m_message);
      }
      return istr;
   }
   auto put(std::ostream& ostr) const->std::ostream& {
      return ostr << m_value;
   }
};
std::ostream& operator<<(std::ostream& ostr, const Int& I) {
   return I.put(ostr);
}
std::istream& operator>>(std::istream& istr, Int& I) {
   return I.get(istr);
}
#endif