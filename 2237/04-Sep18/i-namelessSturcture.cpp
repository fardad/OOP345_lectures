#include <iostream>
using namespace std;
class Student {
   struct {
      string first;
      string last;
   } m_name;
public:
   void foo() {
      auto n = m_name;


   }

};


int main() {


   return 0;
}