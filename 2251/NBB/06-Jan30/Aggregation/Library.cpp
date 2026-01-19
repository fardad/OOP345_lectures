#include <iostream>
#include "Library.h"
#include "Book.h"
using namespace std;
Library::Library(const char* title):m_title(title) {}
int Library::find(const Book& B) {
   int foundIndex = -1;
   for (size_t i = 0; foundIndex == -1 && i < m_noOfBooks; i++) {
      if (B == *m_books[i]) {
         foundIndex = static_cast<int>(i);
      }
   }
   return foundIndex;
}
bool Library::add(const Book& B) {
   int index = find(B);
   if (index == -1) {
      size_t i{};
      const Book** temp = new const Book * [m_noOfBooks + 1];
      for (; i < m_noOfBooks; i++) {
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
      size_t i{}, j{};
      const Book** temp = new const Book * [m_noOfBooks - 1];
      for (; i < m_noOfBooks; i++) {
         if(i!= static_cast<size_t>(index)) (temp[j++] = m_books[i]);
      }
      delete[] m_books;
      m_books = temp;
      m_noOfBooks--;
   }
   return index >= 0;
}
ostream& Library::display(ostream& os)const {
   os << m_title << " library" ;
   if (m_hidBooksInNextPrint) {
      //bool* flag = const_cast<bool*>(&m_hidBooksInNextPrint);
      //*flag = false;
      *(const_cast<bool*>(&m_hidBooksInNextPrint)) = false;
   }else if( m_noOfBooks){
      os << endl << "Books avalilable:";
      for (size_t i = 0; i < m_noOfBooks; i++) {
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
