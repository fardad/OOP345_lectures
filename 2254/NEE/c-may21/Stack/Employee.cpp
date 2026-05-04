#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include <utility>
#include "Employee.h"
using namespace std;
void Employee::setName(const char* name) {
  delete[] m_name;
  m_name = new char[strlen(name) + 1];
  strcpy(m_name, name);
}
Employee::Employee() {
}
Employee::~Employee() {
  delete[] m_name;
}
Employee::Employee(const char* name, unsigned long empno) {
  setName(name);
  m_empno = empno;
}
Employee::Employee(const Employee& e) {
  operator=(e);
}
Employee& Employee::operator=(const Employee& e) {
  setName(e.m_name);
  m_empno = e.m_empno;
  return *this;
}
Employee::Employee(Employee&& e) {
  operator=(std::move(e));
}
Employee& Employee::operator=(Employee&& e) {
  m_name = e.m_name;
  m_empno = e.m_empno;
  e.m_name = nullptr;
  return *this;
}
istream& Employee::read(istream& is) {
  char name[4096];
  is.getline(name, 4095, ':');
  is >> m_empno;
  if (!is.fail()) {
    setName(name);
  }
  return is;
}
ostream& Employee::print(ostream& os)const {
  if (m_name) {
    os << m_name << ":" << m_empno;
  }
  return os;
}
ostream& operator<<(ostream& os, const Employee& E) {
  return E.print(os);
}
istream& operator>>(istream& is, Employee& E) {
  return E.read(is);
}
