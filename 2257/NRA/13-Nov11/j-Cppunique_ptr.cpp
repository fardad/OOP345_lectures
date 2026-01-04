#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;
class Employee {
   double m_salary;
   int m_empno;
   char m_name[31];
public:
   Employee(double sal, int emp, const char* nm) {
      m_salary = sal;
      m_empno = emp;
      strncpy(m_name, nm, 30);
      m_name[30] = '\0';
   }
   double salary()const {
      return m_salary;
   }
   ostream& print(ostream& os)const {
      return os << left << setw(25) << m_name << " Emno: " << setw(7) << m_empno
         << ", Salary: " << setw(10) << fixed << setprecision(2) << right << m_salary;
   }
};
ostream& operator<<(ostream& os, const Employee& E) {
   return E.print(os);
}
int main() {
   unique_ptr<Employee> p(new Employee(123456.45, 12345, "Fred Soley"));
   unique_ptr<Employee> r(new Employee(123456.45, 12335, "Jack Soley"));
   unique_ptr<Employee> q = move(p);
   q = move(r);

   cout << *q << endl;
   cout << q->salary() << endl;


   return 0;
}