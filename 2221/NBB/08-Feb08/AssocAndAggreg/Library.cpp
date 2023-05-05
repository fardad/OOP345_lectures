#include <iostream>
#include "Library.h"
#include "Book.h"
using namespace std;
namespace sdds {
   Library::Library(const char* title) :m_title(title) {
   }
   int Library::find(const Book& B) {
      int foundIndex = -1;
      for (int i = 0; foundIndex == -1 && i < (int)m_noOfBooks; i++) {
         if (B == *m_books[i]) {
            foundIndex = i;
         }
      }
      return foundIndex;
   }
   bool Library::add(const Book& B) {
      int index = find(B);
      if (index == -1) {
         int i;
         const Book** temp = new const Book * [m_noOfBooks + 1];
         for (i = 0; i < (int)m_noOfBooks; i++) {
            temp[i] = m_books[i];
         }
         temp[i] = &B;
         delete[] m_books;
         m_books = temp;
         m_noOfBooks++;
      }
      return index == -1;
   }
   Library& Library::operator<<(Book& B) {
      add(B);
      B.add(*this);
      return *this;
   }
   bool Library::operator==(const Library& L)const {
      return m_title == L.m_title;
   }
   bool Library::remove(const Book& B) {
      int index = find(B);
      if (index >= 0) {
         int i;
         const Book** temp = new const Book * [m_noOfBooks - 1];
         for (i = 0; i < (int)m_noOfBooks; i++) {
            if (i != index) (temp[i] = m_books[i]);
         }
         delete[] m_books;
         m_books = temp;
         m_noOfBooks--;
      }
      return index >= 0;
   }
   ostream& Library::display(ostream& os)const {
      os << m_title << " library";
      if (m_hidBooksInNextPrint) {
         bool* flag = const_cast<bool*>(&m_hidBooksInNextPrint);
         *flag = false;
      }
      else if (m_noOfBooks) {
         os << endl << "Books avalilable:";
         for (unsigned int i = 0; i < m_noOfBooks; i++) {
            os << endl << "   " << hideNextSubContent << *m_books[i];
         }
      }
      return os;
   }
   void Library::hideSubContent() {
      m_hidBooksInNextPrint = true;
   }

   istream& Library::read(std::istream& is) {
      cout << "Enter library name: ";
      return is >> m_title;
   }
   Library::~Library() {
      delete[] m_books;
   }
}