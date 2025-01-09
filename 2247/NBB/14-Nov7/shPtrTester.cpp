#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "ShPtr.h"
using namespace std;
using namespace seneca;
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
   ShPtr<Employee> p( new Employee( 12345.56, 12345, "Fred Soley" ) );
   ShPtr<Employee> q, r = new Employee( 12345.56, 32345, "Jack Soley" );
   q = p;
   r->print( cout ) << endl;
   cout << *p << endl;
   cout << *q << endl;
}

int main( ) {
   test1( );
   return 0;
}