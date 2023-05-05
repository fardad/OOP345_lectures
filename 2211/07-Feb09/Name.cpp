#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Name.h"
#include <cstring>

using namespace std;
namespace sdds {


   Name::Name() {
      init();
   }

   Name::Name(const char* theName) {
      init();
      setName(theName);
   }
   Name::Name(const char* theName, int maxLen) {
      int len = strlen(theName) > size_t(maxLen) ? maxLen : strlen(theName);
      m_value = new char[len + 1];
      strncpy(m_value, theName, len);
      m_value[len] = char(0);
   }

   Name::~Name() { // destructor
      deallocate();
   }

   void Name::init() {
      m_value = nullptr; // wash
   }
   void Name::deallocate() {
      delete[] m_value; // emtpy
      m_value = nullptr;
   }
   Name& Name::setName(const char* theName) {
      deallocate();
      if (theName) {
         m_value = new char[strlen(theName) + 1];
         strcpy(m_value, theName);
      }
      return *this;
   }
   Name& Name::addToName(const char* theValue) {
      if (theValue) {
         int newlen = 0;
         if (m_value) {
            newlen = strlen(m_value);
         }
         newlen += strlen(theValue);
         char* temp = new char[newlen + 1];
         if (m_value) {
            strcpy(temp, m_value);
         }
         else {
            temp[0] = char(0); // '\0' or 0
         }
         strcat(temp, theValue);
         delete[] m_value;
         m_value = temp;
      }
      return *this;
   }
   Name& Name::assign(const Name& N) {
      if (this != &N) {  // OCD
         setName(N.m_value);
      }
      return *this;
   }
   ostream& Name::print(ostream& ostr)const {
      if (m_value) { 
         ostr << m_value;
      }
      else {
         ostr << "Null Name";
      }
      return ostr;
   }




}