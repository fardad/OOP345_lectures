#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Name {
   char* m_first{};
   char* m_last{};
   void set(const char* first, const char* last) {
      delete[] m_first;
      delete[] m_last;
      if (first) {
         m_first = new char[strlen(first) + 1];
         strcpy(m_first, first);
      }
      else {
         m_first = nullptr;
      }
      if (last) {
         m_last = new char[strlen(last) + 1];
         strcpy(m_last, last);
      }
      else {
         m_last = nullptr;
      }
   }
public:
   // Constructor
   Name(const char* first = nullptr, const char* last = nullptr) {
      set(first, last);
   }

   // Destructor
   ~Name() {
      delete[] m_first;
      delete[] m_last;
   }

   // Copy Constructor
   Name(const Name& other) {
      set(other.m_first, other.m_last);
   }
   // Move Constructor
   Name(Name&& other) {
      m_first = other.m_first;
      m_last = other.m_last;
      other.m_first = other.m_last = nullptr;
   }

   // Copy Assignment
   Name& operator=(const Name& other) {
      if (this != &other) {
         set(other.m_first, other.m_last);
      }
      return *this;
   }
   // Move Assignment
   Name& operator=(Name&& other) {
      if (this != &other) {
         m_first = other.m_first;
         m_last = other.m_last;
         other.m_first = other.m_last = nullptr;
      }
      return *this;
   }


   void display(ostream& os = cout) const {
      os << (m_first ? m_first : "") << ' ' << (m_last ? m_last : "");
   }
};
ostream& operator<<(ostream& os, const Name& n) {
   n.display(os);
   return os;
}

Name makeName() {
   Name temp("Alice", "Wonderland");
   return temp;
}

void printByValue(Name n) {
   cout << "Inside printByValue: ";
   n.display();
   cout << '\n';
}
int main() {  
   // Copy constructor via pass-by-value
   printByValue(Name("John", "Doe"));
   Name n2 = makeName();
   cout << "n2: "; n2.display(); cout << '\n';
   return 0;
}