#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Employee {
   string m_name{};
   size_t m_no{};
   double m_salary{};
public:
   istream& read(istream& istr) {
      getline(istr, m_name, ',');
      istr >> m_no;
      istr.ignore(1000, ',');
      istr >> m_salary;
      istr.ignore(1000, '\n');
      return istr;
   }
   ostream& write(ostream& ostr) {
      return ostr << m_name << '\t' << m_no << '\t' << m_salary;
   }
};
istream& operator>>(istream& left, Employee& E) {
   return E.read(left);
}

int main() {
   Employee E;
   cout << "OOP345NBB Oct 30" << endl;
   ifstream filein("data.txt");
   if (filein) {
      while (filein >> E) {
         E.write(cout) << endl;
      }
   }
   else {
      cerr << "File not found!" << endl;
   }
   return 0;
}