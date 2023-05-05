#include <string>
#include <exception>
using namespace std;

#include "Validation.h"
auto badIntExp::what()const noexcept->const char* {
   return m_message.c_str();
}
tooYoungExp::tooYoungExp() {
   m_message = "Too young to drink";
}
tooOldExp::tooOldExp() {
   m_message = "Too old to be in a bar";
}
badMark::badMark() {
   m_message = "Invalid Mark value, [0 <= mark <= 100]";
}



auto ValidAge::operator()(int val, string& messageOut)->void {
   if (val < 19) {
      throw tooYoungExp();
   }
   else if (val > 100) {
      throw tooOldExp();
   }
}

auto ValidMark::operator()(int val, string& messageOut)->void {
   if (val < 0 || val >100) {
      throw badMark();
   }
}