/*Aggregation:
Library has a C-style array of Book pointers.
The Book objects can exist independently of the Library, but the Library manages their existence within its scope.
*/

#include <iostream>
#include <string>
using namespace std;
class Book {
   string m_title;
public:
   Book(string title) :m_title(title) {};
};

class Library {
   string m_name;
   Book* books[1000]{};
   size_t m_bookCount{};
public:
   Library(string name) : m_name{ name } {};
   void addBook(const Book& book) {
      if (m_bookCount < 1000) {
         books[m_bookCount++] = new Book(book);
      }
   }
   virtual ~Library() {
      for (size_t i = 0; i < m_bookCount; i++) {
         delete books[i]; // Deleting books when library is destroyed
      }
   }

};



int main() {
   cout << "OOP345 NBB - 07-Sep26" << endl;
   Book B("C++ reference");
   Library S("Seneca Library");
   S.addBook(B);
   return 0;
}