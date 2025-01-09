#include <iostream>
#include <string>
/*Aggregation:
Library has a C-style array of Book pointers.
The Book objects can exist independently of the Library, but the Library manages their existence within its scope.
*/
using namespace std;
class Book {
   string m_title;
public:
   Book(string title) :m_title(title) {};
};
class Library {
   string m_name;
   Book* m_books[2000]{}; // Aggregation with books using an C - style array.
   size_t m_bookCount{};
public:
   Library(string name):m_name(name){}
   void addBook(const Book& book) {
      if (m_bookCount < 2000) {
         m_books[m_bookCount++] = new Book(book);
      }
   }
   virtual ~Library() {
      for (size_t i = 0; i < m_bookCount; i++) {
         delete m_books[i]; //  Deleting books when library is destroyed
      }
   }
};



int main() {
   cout << "OOP345 ZBB 07-Sep27" << endl;
   Book B("C++ reference");
   Library S("Seneca Library");
   S.addBook(B);
   return 0;
}