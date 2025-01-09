#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "UnPtr.h"
using namespace seneca;
using namespace std;
class Employee {
   double m_salary;
   int m_empno;
   char m_name[31];
public:
   Employee( double sal, int emp, const char* nm ) {
      m_salary = sal;
      m_empno = emp;
      strncpy( m_name, nm, 30 );
      m_name[30] = '\0';
   }
   double salary( )const {
      return m_salary;
   }
   ostream& print( ostream& os )const {
      return os << left << setw( 25 ) << m_name << " Emno: " << setw( 7 ) << m_empno
         << ", Salary: " << setw( 10 ) << fixed << setprecision( 2 ) << right << m_salary;
   }
};
ostream& operator<<( ostream& os, const Employee& E ) {
   return E.print( os );
}
void test1( ) {
   UnPtr<int> p = new int;
   UnPtr<Employee> e = new Employee( 12345.67, 12345, "John Doe" );
   *p = 123;
   double sal = e->salary( );
   cout << *p << endl;
   cout << sal << " | " << *e << endl;
}
void tax( UnPtr<Employee> e ) {
   cout << *e << endl;
   cout << "Tax: " << e->salary( ) * 0.13 << endl;
}
int main( ) {
   UnPtr<Employee> p( new Employee( 123456.45, 12345, "Fred Soley" ) );
   UnPtr<int> ptr( new int );
   UnPtr<int> ptr3( new int );
   *ptr3 = 400;
   *ptr = 1234;
   cout << *ptr << endl;
   cout << *p << endl;
   UnPtr<int> ptr2 = move( ptr );
   if ( ptr )
      cout << *ptr << endl;
   else
      cout << "ptr is null!" << endl;
   cout << *ptr2 << endl;
   ptr = move( ptr2 );
   cout << *ptr << endl;
   ptr = move( ptr3 );
   cout << *ptr << endl;
   tax( move( p ) );
   return 0;
}