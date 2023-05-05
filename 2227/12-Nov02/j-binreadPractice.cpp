#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"
using namespace std;
bool showRec(size_t row, ifstream& F) {
   Employee E;
   F.clear();
   F.seekg(std::streampos((row - 1) * sizeof(Employee)));
   F.read((char*)&E, sizeof(Employee));
   if (F)
      cout << row << ": " << E << endl;
   else
      cout << "Record out of bound!" << endl;
   return !F.fail();
}
int main() {
   Employee E;
   int i = 0;
   ifstream file("employee.bin", ios::binary);
   while (showRec(++i, file));
   showRec(15, file);
   if (!showRec(30, file)) {
      cout << "out of bound!" << endl;
   }
   file.clear();
   file.seekg(0, ios::end);
   cout << "files size: " << file.tellg() << endl;
   cout << "number of recs: " << file.tellg() / sizeof(Employee) << endl;
   file.seekg(0);
   file.read((char*)&E, sizeof(Employee));
   cout << "First Emp rec: " << E << endl;
   file.seekg((std::streamoff)(-1) * sizeof(Employee), ios::end);
   if (file)
      file.read((char*)&E, sizeof(Employee));
   cout << "Last Emp rec: " << E << endl;
   return 0;
}