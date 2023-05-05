#include <iostream>
using namespace std;
#include "validation.h"
#include "Int.h"

Int::Int(int value, Validation* validationFunctor) 
   :m_value{ value }, m_message{}, m_valid{ validationFunctor } {
}
auto Int::set(Validation* validationFunctor)->void {
   m_valid = validationFunctor;
}

auto Int::get(istream& istr)->istream& {
   bool done = false;
   isValid = true;
   do {
      if (istr >> m_value) {
         done = !m_valid || (*m_valid)(m_value, m_message);
      }
      else {
         m_message = "Invalid Integer, try again: ";
         istr.clear();
      }         
      istr.ignore(1000, '\n');
      if (m_valid && (m_valid->tries() > 3)) {
         isValid = false;
      }
   } while (isValid && !done && cout << m_message);
   return istr;
}
auto Int::put(ostream& ostr) const->ostream& {
   return ostr << m_value;
}
Int::operator bool() const {
   return isValid;
}
auto operator<<(ostream& ostr, const Int& I)->ostream& {
   return I.put(ostr);
}
auto operator>>(istream& istr, Int& I)->istream& {
   return I.get(istr);
}