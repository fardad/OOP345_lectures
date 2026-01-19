#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include "IOAble.h"
#include "Title.h"
class Library;
class Book:public IOAble {
   Title m_title{};
   size_t m_isbn{};
   const Library** m_libs{};
   size_t m_noOfLibs{};
   bool m_hideLibsInNextPrint{};
   int find(const Library& L);
public:
   Book(const char* title, int isbn);
   Book(const Book& B)=delete;
   Book& operator=(const Book& B) = delete;
   bool operator==(const Book& B)const;
   bool add(const Library& B);
   Book& operator<<( Library& B);
   void hideSubContent();
   bool remove(const Library& B);
   std::ostream& display(std::ostream& os = std::cout)const;
   std::istream& read(std::istream& is = std::cin);
};
#endif