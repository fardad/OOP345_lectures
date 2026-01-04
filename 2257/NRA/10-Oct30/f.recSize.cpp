#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Employee {
   char m_name[41]{};
   size_t m_no{};
   double m_salary;
public:
   Employee() = default;
   istream& read(istream& istr ) {
      istr.getline(m_name,41, ',');
      istr >> m_no;
      istr.ignore(1000, ',');
      istr >> m_salary;
      istr.ignore(1000, '\n');
      return istr;
   }
   ostream& write(ostream& ostr) {
      return ostr << m_name << '\t' << m_no << '\t' << m_salary;
   }
};
istream& operator>>(istream& left, Employee& E) {
   return E.read(left);
}

using namespace std;
int main() {
   Employee E;
   cout << sizeof(Employee) << endl;
   return 0;
}