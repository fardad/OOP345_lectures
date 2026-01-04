#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Employee {
   char m_name[41]{};
   size_t m_no{};
   double m_salary;
public:
   ifstream& read(ifstream& istr) {
      istr.getline(m_name, 41, ',');
      istr >> m_no;
      istr.ignore(1000, ',');
      istr >> m_salary;
      istr.ignore(1000, '\n');
      return istr;

   }
   ostream& write(ostream& ostr) {
      return ostr << m_name << '\t' << m_no << '\t' << m_salary;
   }
   ofstream& write(ofstream& ostr) {
      ostr.write(reinterpret_cast<const char*>(this), sizeof(Employee));
      return ostr;
   }
};

using namespace std;
int main() {
   Employee E;
   cout << "OOP345NBB Oct 30" << endl;
   string s;
   ifstream filein("data.txt");
   ofstream binFile("data.bin", ios::binary);
   if (filein) {
      while (E.read(filein)) {
         E.write(binFile) << endl;
      }
   }
   else {
      cerr << "File not found!" << endl;
   }
   cout << s << endl;
   return 0;
}