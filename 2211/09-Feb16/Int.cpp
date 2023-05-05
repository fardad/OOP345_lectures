#include <iostream>
using namespace std;
#include "Int.h"
#include "Validation.h"

Int::Int(int value, Validation* validationFunctor) {
   m_value = value;
   m_valid = validationFunctor;
}

void Int::set(Validation* validationFunctor) {
   m_valid = validationFunctor;
}
auto Int::get(istream& istr)->istream& {
   bool done = false;
   do {
/*1      istr >> m_value;
      if (!istr.fail()) {*/
/*2      istr >> m_value;
      if(istr){*/
      if(istr >> m_value){
         done = !m_valid || (*m_valid)(m_value, m_message);
      }
      else{
            m_message = "Invalid Integer, try agian: ";
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
