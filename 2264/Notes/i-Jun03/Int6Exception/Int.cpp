#include <iostream>
using namespace std;
#include "Validation.h"
#include "Int.h"

Int::Int(Validation& validationFunctor):m_valid(validationFunctor){}

auto Int::get(istream& istr)->istream& {
   if ((istr >> m_value).fail()) {
      istr.clear();
      throw badIntExp();
   }
   else {
      m_valid(m_value, m_message);
   }
   return istr;
}
auto Int::put(ostream& ostr) const->ostream& {
   return ostr << m_value;
}
auto operator<<(ostream& ostr, const Int& I)->ostream& {
   return I.put(ostr);
}
auto operator>>(istream& istr, Int& I)->istream& {
   return I.get(istr);
}