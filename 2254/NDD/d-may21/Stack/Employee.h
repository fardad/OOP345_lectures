#ifndef EMPLOYEE_H__
#define EMPLOYEE_H__
#include <iostream>
using namespace std;
class Employee {
  char* m_name = nullptr;
  unsigned long m_empno = -1;
  void setName(const char* name);
public:
  Employee();
  ~Employee();
  Employee(const char* name, unsigned long empno);
  Employee(const Employee& e);
  Employee& operator=(const Employee& e);
  Employee(Employee&& e);
  Employee& operator=(Employee&& e);
  std::istream& read(std::istream& is);
  std::ostream& print(std::ostream& os)const;
};
std::ostream& operator<<(std::ostream& os, const Employee& E);
std::istream& operator>>(std::istream& is,Employee& E);

#endif // 
