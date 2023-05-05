#include <iostream>
#include <fstream>
#include <iomanip>
#include "BEmployee.h"
using namespace std;
Employee::Employee(double sal, int emp, const char* nm) {
   size_t i{};
   salary = sal;
   empno = emp;
   for (i = 0u; nm[i] && i < 51u; name[i] = nm[i++]);
   name[i] = char(0);
}
bool Employee::operator<(const Employee& rOper) const {
   size_t i = 0;
   while (name[i] && rOper.name[i] && name[i] == rOper.name[i]) i++;
   return name[i] < rOper.name[i];
}
ostream& Employee::print(ostream& os)const {
   return os << name << "," << empno << "," << fixed << setprecision(2) << salary;
}
istream& Employee::read(istream& ifs) {
   ifs.read((char*)this, sizeof(Employee));
   return ifs;
}
ostream& operator<<(ostream& os, const Employee& E) {
   return E.print(os);
}
istream& operator>>(istream& ifs, Employee& E) {
   return E.read(ifs);
}