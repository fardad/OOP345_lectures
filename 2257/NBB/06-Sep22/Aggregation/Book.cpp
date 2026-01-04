#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;
Book::Book(const char* title, int isbn) :m_title(title), m_isbn(isbn) {}

bool Book::operator==(const Book& B)const {
   return m_isbn == B.m_isbn;
}

std::ostream& Book::display(std::ostream& os )const {
   os << m_title << ": " << m_isbn;
   if (m_hideLibsInNextPrint) {
      bool* flag = const_cast<bool*>(&m_hideLibsInNextPrint);
      *flag = false;
   } else if (m_noOfLibs) {
      os << endl << "This book is available in following Libraries:";
      for (size_t i = 0; i < m_noOfLibs; i++) {
         os << endl << "   " << hideNextSubContent << *m_libs[i];
      }
   }
   return os;
}
void Book::hideSubContent() {
   m_hideLibsInNextPrint = true;
}
std::istream& Book::read(std::istream& is ) {
   cout << "Title: ";
   is >> m_title;
   cout << "ISBN: ";
   is >> m_isbn;
   is.ignore(1000, '\n');
   return is;
}


int Book::find(const Library& B) {
   int foundIndex = -1;
   for (size_t i = 0; foundIndex == -1 && i < m_noOfLibs; i++) {
      if (B == *m_libs[i]) {
         foundIndex = static_cast<int>(i);
      }
   }
   return foundIndex;
}
bool Book::add(const Library& B) {
   int index = find(B);
   if (index == -1) { // adding the library of book by resizing the libray pointer array
      size_t i{};
      const Library** temp = new const Library* [m_noOfLibs + 1];
      for (; i < m_noOfLibs; i++) {
         temp[i] = m_libs[i];
      }
      temp[i] = &B;
      delete[] m_libs;
      m_libs = temp;
      m_noOfLibs++;
   }
   return index == -1;
}
Book& Book::operator<<( Library& L) {
   add(L);
   return *this;
}
bool Book::remove(const Library& B) {
   int index = find(B);
   if (index >= 0) { // shroten the dynamic libarary pointer array by shifiting to left
      size_t i{}, j{};
      const Library** temp = new const Library * [m_noOfLibs - 1];
      for (; i < m_noOfLibs; i++) {
         if (i != static_cast<size_t>(index)) (temp[j++] = m_libs[i]);
      }
      delete[] m_libs;
      m_libs = temp;
      m_noOfLibs--;
   }
   return index >= 0;
}
