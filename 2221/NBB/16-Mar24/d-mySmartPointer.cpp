#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

template <typename type>
class pointer {
   type* m_ptr{};
public:
   pointer(type* ptr) :m_ptr{ ptr } {
   }
   pointer(const pointer&) = delete;
   void operator=(const pointer&) = delete;
   pointer(pointer&& ptr)noexcept {
      m_ptr = ptr.m_ptr;
      ptr.m_ptr = nullptr;
   }
   pointer& operator=(pointer&& ptr)noexcept {
      if (this != &ptr) {
         delete m_ptr;
         m_ptr = ptr.m_ptr;
         ptr.m_ptr = nullptr;
      }
      return *this;
   }
   type& operator*() {
      return *m_ptr;
   }
   type* operator->() {
      return m_ptr;
   }
   operator const void* ()const {
      return static_cast<const void*>(m_ptr);
   }
   virtual ~pointer() {
      delete m_ptr;
   }
};






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
   pointer<Employee> p(new Employee);
   cin >> *p;
   E = *p;
}
int main() {
   Employee E;
   try {
      getEmp(E);
      cout << E << endl;
   }
   catch (const char* err) {
      cerr << err << endl;
   }
   return 0;
}

