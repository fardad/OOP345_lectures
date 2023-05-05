// this one has a bug and needs to get fixed.
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
   ostream& print(ostream& os)const {
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

template<class T>
class sPtr {
private:
   T* m_ptr = nullptr;
   size_t* m_ptrCnt = nullptr;
   void wipeout() {
      if(m_ptrCnt) (*m_ptrCnt)--;
      if(m_ptrCnt && *m_ptrCnt == 0) {
         delete m_ptr;
         delete m_ptrCnt;
      }
   }
public:
   sPtr(T* ptr = nullptr) : m_ptr{ ptr }, m_ptrCnt{ new size_t(ptr ? 1 : 0) } {   } // constr

   sPtr(const sPtr& obj) { // copy constr
      m_ptr = obj.m_ptr; // share addresses
      m_ptrCnt = obj.m_ptrCnt;
      if(obj.m_ptr) {
         (*m_ptrCnt)++; // if not null, add one to counter
      }
   }
   sPtr& operator=(const sPtr& obj) { // copy assign
      if(this != &obj) {
         wipeout(); // wipe out already existing data
         m_ptr = obj.m_ptr; // share addresses
         m_ptrCnt = obj.m_ptrCnt;
         if(obj.m_ptr) {
            (*m_ptrCnt)++; // if null, increment add one to counter
         }
      }
      return *this;
   }

   sPtr(sPtr&& dyingObj)noexcept { // move constr
      m_ptr = dyingObj.m_ptr; // share the underlying pointer
      m_ptrCnt = dyingObj.m_ptrCnt;
      dyingObj.m_ptr = nullptr;
      dyingObj.m_ptrCnt = nullptr; // clean the dying object
   }

   sPtr& operator=(sPtr&& dyingObj) { // move assign
      if(this != &dyingObj) {
         wipeout(); // wipe out already existing data
         m_ptr = dyingObj.m_ptr; // share the underlying pointer
         m_ptrCnt = dyingObj.m_ptrCnt;
         dyingObj.m_ptr = dyingObj.m_ptrCnt = nullptr; // clean the dying object
      }
      return *this;
   }

   size_t count() const {
      return *m_ptrCnt; // *m_ptrCnt
   }


   T* operator->() {
      return m_ptr;
   }

   T& operator*() const {
      return *m_ptr;
   }

   operator const void* ()const {
      return static_cast<const void*>(m_ptr);
   }

   ~sPtr() {
      wipeout();
   }
};
void showEmp(sPtr<Employee> eptr) {
   cout << *eptr << endl;
}
int main() {
   sPtr<int> a(new int);
   *a = 12;
   cout << *a << endl;
   sPtr<int> b(a);
   sPtr<int> c(b);
   (*c)++;
   sPtr<int> d = move(a);
   if(a)
      cout << *a << endl;
   if(d)
      cout << *d << endl;
   cout << *b << *c << endl;
   sPtr<Employee> p(new Employee(123456.78, 123, "Fred Soley"));
   sPtr<Employee> q = p;
   showEmp(p);
   showEmp(q);
   cout << "----------------------------------------------" << endl;
   cout << *p << endl << *q << endl;
   cout << "The Salary is: " << q->salary() << endl;
   return 0;
}
