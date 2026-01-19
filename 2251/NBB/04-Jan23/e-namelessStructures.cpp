#include <string>
using namespace std;
class Student {
   double m_gpa;
   struct {
      string first;
      string last;
   } m_name;
   int m_semester;

public:
   void foo( ) {
      m_gpa = 4.0;
      m_semester = 3;
      m_name.first = "jack";
      m_name.last = "Black";
      auto tempName = m_name;// how to create a copy of a nameless struct

   }
};
