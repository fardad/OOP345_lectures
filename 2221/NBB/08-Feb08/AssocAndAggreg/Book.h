#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H_
#include <iostream>
#include "IOAble.h"
#include "Title.h"
namespace sdds {
   class Library;
   class Book :public IOAble {
      Title m_title;
      unsigned int m_isbn = 0;
      const Library** m_libs = nullptr;
      unsigned int m_noOfLibs = 0u;
      int find(const Library& L);
      bool m_hideLibsInNextPrint = false;
   public:
      Book(const char* title, int isbn);
      Book(const Book& B) = delete;
      Book& operator=(const Book& B) = delete;
      bool operator==(const Book& B)const;
      bool add(const Library& B);
      Book& operator<<(Library& B);
      void hideSubContent();
      bool remove(const Library& B);
      std::ostream& display(std::ostream& os = std::cout)const;
      std::istream& read(std::istream& is = std::cin);
   };
}
#endif