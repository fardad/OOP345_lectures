#include <iostream>
#include <functional>
using namespace std;
#include "Int.h"

Int::Int(std::function<bool(int, string&)> lamdaValidArg) {
   lamdaValid = lamdaValidArg;
}

void Int::set(std::function<bool(int, string&)> lamdaValidArg) {
   lamdaValid = lamdaValidArg;
}

auto Int::get(istream& istr)->istream& {
   bool done = false;
   do {
      if (istr >> m_value) {
         done = !lamdaValid || lamdaValid(m_value, m_message);
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