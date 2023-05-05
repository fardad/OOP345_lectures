#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <memory>
using namespace std;



class Employee {
   double m_salary{};
   int m_empno{};
   char m_name[31]{};
public:
   Employee() = default;
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
   istream& read(istream& is) {
      cout << "Name: ";
      is.getline(m_name, 31);
      if(is.fail()) throw "Name too long!";
      cout << "Emp no: ";
      is >> m_empno;
      if (is.fail()) throw "Invalid Integer!";
      if (m_empno < 100000 || m_empno > 999999) throw "Invalid Employee number!";
      is >> m_salary;
      if (is.fail()) throw "Invlaid money value!";
      if (m_salary < 10000 || m_salary > 1000000) throw "Invalid Salry amount!";
      return is;
   }
};
ostream& operator<<(ostream& os, const Employee& E) {
   return E.print(os);
}
istream& operator>>(istream& is, Employee& E) {
   return E.read(is);
}
void getEmp(Employee& E) {
   unique_ptr<Employee> p(new Employee);
   cin >> *p;
   E = *p;
}


void tax(unique_ptr<Employee> e) {
   cout << *e << endl;
   cout << "Tax: " << e->salary() * 0.13 << endl;
}
int main() {
   unique_ptr<Employee> p(new Employee(123456.78, 123, "Fred Soley"));
   unique_ptr<int> ptr(new int);
   cout << "int value: ";
   cin >> *ptr;
   cout << *ptr << endl;
   unique_ptr<int> ptr2 = move(ptr);
   cout << *ptr2 << endl;
   cout << "in main: " << *p << endl;
   tax(move(p));
   return 0;
}
