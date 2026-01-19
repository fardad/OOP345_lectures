#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <memory>
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



void EmpMaker( const char* name, int empNo, double sal ) {
   shared_ptr<Employee> p( new Employee( sal, empNo, name ) );
   cout << *p << endl;
   shared_ptr<Employee> q( p );
   cout << "The Salary is: " << q->salary( ) << endl;
}

int main( ) {
   shared_ptr<int> a( new int );
   *a = 12;
   cout << *a << endl;
   shared_ptr<int> b( a );
   shared_ptr<int> c( b );
   (*c)++;
   shared_ptr<int> d = move( a );
   if ( a != nullptr )
      cout << *a << endl;
   if ( d != nullptr )
      cout << *d << endl;
   cout << *b << *c << endl;
   EmpMaker( "Fred Soley", 123, 123456.78 );
   return 0;
}
