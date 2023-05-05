#pragma once
#include <iostream>
class Employee {
   double salary;
   int empno;
   char name[50];
public:
   Employee(double sal = 0.0, int emp = 0, const char* nm = "");
   bool operator<(const Employee&)const;
   std::ostream& print(std::ostream& os)const;
   std::istream& read(std::istream& ifs);
};
std::ostream& operator<<(std::ostream& os, const Employee& E);
std::istream& operator>>(std::istream& ifs, Employee& E);