#ifndef LIBRARY_H_
#define LIBRARY_H_
#include "IOAble.h"
#include "Title.h"
class Book;
class Library:public IOAble {
   Title m_title{};
   const Book** m_books{};
   size_t m_noOfBooks{};
   int find(const Book& B);
   bool m_hidBooksInNextPrint{};
public:
   Library(const char* m_title);
   Library(const Library& C) = delete;
   bool operator=(const Library& C) = delete;
   bool operator==(const Library& B)const;
   bool add(const Book& B);
   Library& operator<<(Book& B);
   void hideSubContent();
   bool remove(const Book& B);
   std::ostream& display(std::ostream& os = std::cout )const;
   std::istream& read(std::istream& is = std::cin);
   virtual ~Library();
};
#endif // !LIBRARY_H_
