#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;
namespace sdds {
   Book::Book(const char* title, int isbn) :m_title(title), m_isbn(isbn) {
   }
   //Book::Book(const Book& B) {
   //   operator=(B);
   //}
   //Book& Book::operator=(const Book& B) {
   //   if (this != &B) {
   //      m_title = B.m_title;
   //      m_isbn = B.m_isbn;
   //   }
   //   return *this;
   //}
   bool Book::operator==(const Book& B)const {
      return m_isbn == B.m_isbn;
   }

   std::ostream& Book::display(std::ostream& os)const {
      os << m_title << ": " << m_isbn;
      if (m_hideLibsInNextPrint) {
         bool* flag = const_cast<bool*>(&m_hideLibsInNextPrint);
         *flag = false;
      }
      else if (m_noOfLibs) {
         os << endl << "This book is available in following Libraries:";
         for (unsigned int i = 0; i < m_noOfLibs; i++) {
            os << endl << "   " << hideNextSubContent << *m_libs[i];
         }
      }
      return os;
   }
   void Book::hideSubContent() {
      m_hideLibsInNextPrint = true;
   }
   std::istream& Book::read(std::istream& is) {
      cout << "Title: ";
      is >> m_title;
      cout << "ISBN: ";
      is >> m_isbn;
      is.ignore(1000, '\n');
      return is;
   }


   int Book::find(const Library& B) {
      int foundIndex = -1;
      for (int i = 0; foundIndex == -1 && i < (int)m_noOfLibs; i++) {
         if (B == *m_libs[i]) {
            foundIndex = i;
         }
      }
      return foundIndex;
   }
   bool Book::add(const Library& B) {
      int index = find(B);
      if (index == -1) {
         int i;
         const Library** temp = new const Library * [m_noOfLibs + 1];
         for (i = 0; i < (int)m_noOfLibs; i++) {
            temp[i] = m_libs[i];
         }
         temp[i] = &B;
         delete[] m_libs;
         m_libs = temp;
         m_noOfLibs++;
      }
      return index == -1;
   }
   Book& Book::operator<<(Library& L) {
      add(L);
      return *this;
   }
   bool Book::remove(const Library& B) {
      int index = find(B);
      if (index >= 0) {
         int i;
         const Library** temp = new const Library * [m_noOfLibs - 1];
         for (i = 0; i < (int)m_noOfLibs; i++) {
            if (i != index) (temp[i] = m_libs[i]);
         }
         delete[] m_libs;
         m_libs = temp;
         m_noOfLibs--;
      }
      return index >= 0;
   }
}