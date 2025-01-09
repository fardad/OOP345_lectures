#include <iostream>
#include <string>
/*Association:
Teacher has a C-style array of Student pointers.
The Student objects can exist independently of the Teacher.
*/
using namespace std;
class Student {
   string m_name;
public:
   Student(string name) :m_name{ name } {};
};
class Teacher {
   string m_name;
   Student* m_students[45]{}; // Association with student using an C-style array.
   size_t m_studentCount{};
public:
   Teacher(string name) :m_name(name) {};
   void addStduent(Student* student) {
      if (m_studentCount < 45) {
         m_students[m_studentCount++] = student;
      }
   }
   virtual ~Teacher() = default;
};

int main() {
   cout << "OOP345 ZBB 07-Sep27" << endl;
   Student S[2] = { {"Siavash"}, {"Tein"} };
   Teacher F("Fardad");
   for (size_t i = 0; i < 2; i++) {
      F.addStduent(&S[i]);
   }
   return 0;
}