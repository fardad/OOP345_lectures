#pragma once
#ifndef TITLE_H__
#define TITLE_H__
#include <iostream>
#include "IOAble.h"
const size_t MaxTitleLen = 70u;
class Title: public IOAble {
   char* m_value = nullptr;
   static char* allocopy(const char* value);
public:
   Title(const char* value = "");
   Title(const Title& T);
   Title& operator=(const Title& T);
   bool operator==(const Title& B)const;
   void hideSubContent();
   virtual ~Title();
   std::ostream& display(std::ostream& os = std::cout)const;
   std::istream& read(std::istream& is = std::cin);
};

#endif
