#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
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
   ostream& print(ostream& os=cout)const {
      return os << left << setw(25) << m_name << " Emno: " << setw(7) << m_empno
         << ", Salary: " << setw(10) << fixed << setprecision(2) << right << m_salary;
   }
   ~Employee() {
      clog << m_name << " is dying!" << endl;
   }
};
ostream& operator<<(ostream& os, const Employee& E) {
   return E.print(os);
}




template<typename T>
class uPtr {
   T* m_ptr{};
public:
   uPtr(T* ptr=nullptr) :m_ptr{ ptr } {};
   uPtr(const uPtr&) = delete;
   void operator=(const uPtr&) = delete;
   uPtr(uPtr&& sp)noexcept {
      m_ptr = sp.m_ptr;
      sp.m_ptr = nullptr;
   }
   uPtr& operator=(uPtr&& sp)noexcept {
      if(this != &sp) {
         delete m_ptr;
         m_ptr = sp.m_ptr;
         sp.m_ptr = nullptr;
      }
      return *this;
   }
   T& operator*() {
      return *m_ptr;
   }
   T* operator->() {
      return m_ptr;
   }
   operator const void* ()const {
      return static_cast<const void*>(m_ptr);
   }
   ~uPtr() {
      delete m_ptr;
   }
};


int main() {
   //clog.setstate(ios::failbit);
   uPtr<Employee> p(new Employee(123456.45, 12345, "Fred Soley"));
   uPtr<int> ptr = new int;
   uPtr<int> ptr2 = move(ptr);
   ptr = move(ptr2);
   uPtr<Employee> p2;

   *ptr = 123;
   if(p) {
      p->print() << endl;
   }
   else {
      cout << "ptr is null" << endl;
   }
   p2 = move(p);
   cout << *p2 << endl;
   return 0;
}
