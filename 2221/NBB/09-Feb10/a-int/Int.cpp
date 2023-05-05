#include <iostream>
using namespace std;
#include "Int.h"

Int::Int(int value) :m_value{ value } {
}
auto Int::valid() -> bool {
   bool res = true;
   if (m_value < 0 || m_value > 100) {
      m_message = "Invalid Mark, try again: ";
      res = false;
   }
   return res;
}

auto Int::get(istream& istr)->istream& {
   bool done = false;
   do {
      if (istr >> m_value) {
         done = valid();
      }
      else {
         m_message = "Invalid Integer, try again: ";
         istr.clear();
      }         
      istr.ignore(1000, '\n');
   } while (!done && cout << m_message);
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