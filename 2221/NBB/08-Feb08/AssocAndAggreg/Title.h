#pragma once
#ifndef SDDS_TITLE_H
#define SDDS_TITLE_H
#include <iostream>
#include "IOAble.h"
namespace sdds {
   const unsigned int MaxTitleLen = 70u;
   class Title : public IOAble {
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
}
#endif
