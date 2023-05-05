#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
class Employee {
   double salary;
   int empno;
   char name[31];
public:
   Employee(double sal, int emp, const char* nm) {
      salary = sal;
      empno = emp;
      strncpy(name, nm, 30);
      name[30] = '\0';
   }
   bool operator==(const char* ename)const {
      return strcmp(name, ename) == 0;
   }
   bool operator > (double val)const {
      return salary > val;
   }
   bool operator>(const Employee& E)const {
      return strcmp(name, E.name) > 0;
   }
   operator double()const {
      return salary;
   }
   ostream& print(ostream& os)const {
      return os << left << setw(25) << name << " Emno: " << setw(7) << empno
         << ", Salary: " << setw(10) << fixed << setprecision(2) << right << salary;
   }
};
ostream& operator<<(ostream& os, const Employee& E) {
   return E.print(os);
}

int main() {
   int ints[]{ 1,3,4,5,6,7,8 };
   vector<Employee> E = {
     {12345.67,10235,"Homer Simpson"},
     {23456.89,11236,"Ned Flanders"},
     {34567.9,12495,"Waylon Smithers"},
     {45678,13795,"Lenny Leonard"},
     {56789.1,14236,"Edna Krabappel"},
     {97453.25,15888,"Barry Mackleberry"},
     {512526.32,16852,"Charles Montgomery Burns"},
     {25364.25,17526,"Larry Burns"},
     {12365.32,18369,"Carl Carlson"},
     {12586.25,19485,"Chip Davis"},
     {12893.25,20159,"Joey Crusher"},
     {12369.33,21478,"Jack Marley"},
     {48963.55,22458,"Robert Marlow"},
     {78952.33,23584,"Eugene Fisk"},
     {19379.44,24896,"Mindy Simmons"},
     {12369.55,25789,"Frank Grimes"},
     {79356.33,26741,"Wayne Slater"},
     {82269.55,27596,"Herbert Powell"},
     {16982.22,28456,"Hans Moleman"},
   };
   cout << E.size() << endl;
   vector<double> taxes(E.size(), 0.13);
   vector<double> owing(E.size());

   // Iterator used to store the position  
   // of searched element 
   vector<Employee>::iterator it;

   // Print Original Vector 
   cout << "Employees: " << endl;
   int i;
   for (i = 0; i < E.size(); i++)
      cout << setw(2) << (i + 1) << "- " << E[i] << endl;
   i = 0;
   for (auto& elm : E) {
      cout << setw(2) << (++i) << "- " << elm << endl;
   }

   // Element to be searched 
   char name[] = "Mindy Simmons";

   // find function call 
   it = find(E.begin(), E.end(), name);
   if (it != E.end()) {
      cout << "Employee: " << endl << *it << endl << "Found at position : ";
      cout << it - E.begin() + 1 << "\n";
   }
   else
      cout << "Element not found.\n\n";
   int num = count_if(E.begin(), E.end(), 
      [](const Employee& E) {return E > 80000.00; });
   cout << num << " Employees make more than 80000.00" << endl;

   transform(E.begin(), E.end(), taxes.begin(),
      owing.begin(), multiplies<double>());
   for_each(owing.begin(), owing.end(), 
      [](double val) {cout << setprecision(2) << val << " "; });
   cout << endl;
   for (i = 0; i < E.size(); i++) {
      cout << setw(2) << (i + 1) << "- " << E[i] << ", owing tax: " << owing[i] << endl;
   }


   cout << "descending sort: " << endl;
   sort(E.begin(), E.end(), [](const Employee& a, const Employee& b) {return a > b; });
   i = 0;
   for (auto elm : E) {
      cout << setw(2) << (++i) << "- " << elm << endl;
   }
   cout << "Ascending sort: " << endl;
   sort(E.begin(), E.end(), [](const Employee& a, const Employee& b) {return !(a > b); });
   i = 0;
   for (auto elm : E) {
      cout << setw(2) << (++i) << "- " << elm << endl;
   }
   cout << endl;
   for_each(ints, ints + 5, [](int p) {cout << p << " "; });
   cout << endl;
   return 0;
}