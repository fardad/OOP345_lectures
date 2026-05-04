#pragma once
#include <iostream>
#include <fstream>
class Employee {
   double salary{};
   int empno{};
   char* name{};
public:
   static void strcpy(char* des, const char* src);
   static size_t strlen(const char* s);
   Employee(double sal = 0.0, int emp = 0, const char* nm = "");
   Employee(const Employee&);
   Employee(Employee&&);
   Employee& operator=(const Employee&);
   Employee& operator=(Employee&&);
   ~Employee();
   bool operator<(const Employee& rOper) const;
   std::ostream& print(std::ostream& os)const;
   bool write(std::ofstream& ofs, std::ofstream& nfs)const;
   bool read(std::ifstream& ifs, std::ifstream& nfs);
};
std::ostream& operator<<(std::ostream& os, const Employee& E);
