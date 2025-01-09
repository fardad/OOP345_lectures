#include <iostream>
#include <string>
/*Association:
Teacher has a C-style array of Student pointers.
The Student objects can exist independently of the Teacher.
*/
using namespace std;
class Student {
public:
   string m_name;
   Student(string name) : m_name(name) {}
};

class Teacher {
   string m_name;
   Student* students[45]{};  // Association with student using C style array
   int m_studentCount{};
public:
   Teacher(string name) : m_name{ name } {};
   void addStudent(Student* student) {
      if (m_studentCount < 45) {
         students[m_studentCount++] = student;
      }
   }
   virtual ~Teacher() = default;
};

int main() {
   cout << "OOP345 NBB - 07-Sep26" << endl;
   Student M("Marcos");
   Teacher* F= new Teacher("Fardad");
   F->addStudent(&M);
   delete F; // will not remove M 
   return 0;
}