#include <iostream>
#include <fstream>
#include <iomanip>
#include "DEmployee.h"
using namespace std;
void Employee::strcpy(char* des, const char* src) {
   while (src && des && *src) *des++ = *src++;
   if(des)*des = 0;
}
size_t Employee::strlen(const char* s) {
   size_t i = 0;
   while (s && s[i])i++;
   return i;
}
Employee::Employee(double sal, int emp, const char* nm) {
   salary = sal;
   empno = emp;
   name = new char[strlen(nm) + 1];
   strcpy(name, nm);
}
Employee::Employee(const Employee& E) {
   operator=(E);
}
Employee::Employee(Employee&& E) {
   operator=(move(E));
}
Employee& Employee::operator=(const Employee& E) {
   if (this != &E) {
      delete[] name;
      name = new char[strlen(E.name) + 1];
      strcpy(name, E.name);
      salary = E.salary;
      empno = E.empno;
   }
   return *this;
}
Employee& Employee::operator=(Employee&& E) {
   if (this != &E) {
      delete[] name;
      name = E.name;
      E.name = nullptr;
      salary = E.salary;
      empno = E.empno;
   }
   return *this;
}
Employee::~Employee() {
   delete[] name;
}
bool Employee::operator<(const Employee& rOper) const {
   size_t i = 0;
   while (name && rOper.name && name[i] && rOper.name[i] && name[i] == rOper.name[i]) i++;
   return name && rOper.name && name[i] < rOper.name[i];
}
ostream& Employee::print(ostream& os)const {
   return os << name << "," << empno << "," << fixed << setprecision(2) << salary;
}
bool Employee::write(std::ofstream& ofs, ofstream& nfs) const {
   std::streampos nameLoc = nfs.tellp();
   size_t nameLen = strlen(name);
   nfs.write(name, nameLen);
   ofs.write((const char*)this, sizeof(*this));
   ofs.write((const char*)&nameLoc, sizeof(nameLoc));
   ofs.write((const char*)&nameLen, sizeof(nameLen));
   return ofs && nfs;
}
bool Employee::read(ifstream& ifs, ifstream& nfs) {
   std::streampos  nameLoc{};
   size_t nameLen{};
   delete[] name;
   ifs.read((char*)this, sizeof(*this));
   ifs.read((char*)&nameLoc, sizeof(nameLoc));
   ifs.read((char*)&nameLen, sizeof(nameLen));
   if (ifs) {
      name = new char[nameLen + 1];
      name[nameLen] = 0;
      nfs.seekg(nameLoc);
      nfs.read(name, nameLen);
   }
   else {
      name = nullptr;
   }
   return ifs && nfs;
}
ostream& operator<<(ostream& os, const Employee& E) {
   return E.print(os);
}
