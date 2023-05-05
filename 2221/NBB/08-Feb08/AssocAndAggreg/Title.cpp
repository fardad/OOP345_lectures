#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Title.h"
using namespace std;
namespace sdds {
   char* Title::allocopy(const char* value) {
      char* cmem;
      size_t len = strlen(value);
      (len > MaxTitleLen) && (len = MaxTitleLen);
      cmem = new char[len + 1];
      cmem[len] = 0;
      return strncpy(cmem, value, len);
   }
   Title::Title(const char* value) {
      m_value = allocopy(value);
   }
   Title::Title(const Title& T) {
      operator=(T);
   }
   void Title::hideSubContent() {
   }
   Title& Title::operator=(const Title& T) {
      if (this != &T) {
         m_value = allocopy(T.m_value);
      }
      return *this;
   }
   Title::~Title() {
      delete[] m_value;
   }
   ostream& Title::display(ostream& os)const {
      return os << m_value;
   }
   bool Title::operator==(const Title& T)const {
      return strcmp(m_value, T.m_value) == 0;
   }
   istream& Title::read(std::istream& is) {
      char buf[MaxTitleLen + 1];
      is.getline(buf, MaxTitleLen + 1, '\n');
      if (cin.fail()) {
         cin.clear();
         cin.ignore(1000, '\n');
      }
      m_value = allocopy(buf);
      return is;
   }
}