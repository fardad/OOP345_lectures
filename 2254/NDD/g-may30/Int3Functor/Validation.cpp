#include <string>
using namespace std;
#include "validation.h"
ValidAge::ValidAge(int min, int max) :m_minAge{ min }, m_maxAge{ max } {};
auto ValidAge::operator()(int val, string& messageOut)->bool {
   bool res = false;
   if (val < m_minAge) {
      messageOut = "Too young to drink!, next please (No of tries, " + to_string(noOfValidations) + "): ";
      noOfValidations++;
   }
   else if (val > m_maxAge) {
      messageOut = "This doesn't seem like a valid age value\nplease try again (No of tries, " + to_string(noOfValidations) + "): ";
      noOfValidations++;
   }
   else {
      res = true;
      noOfValidations = 0;
   }
   return res;
}

auto ValidMark::operator()(int val, string& messageOut)->bool {
   bool res = true;
   if (val < 0 || val >100) {
      messageOut = "Invalid Mark value, [0<=mark<=100] (No of tries, " + to_string(noOfValidations) + "): ";
      noOfValidations++;
      res = false;
   }
   else {
      noOfValidations = 0;
   }
   return res;
}