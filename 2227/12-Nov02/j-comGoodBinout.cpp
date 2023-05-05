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
   int i = 1;
   ifstream file("employee.bin", ios::binary);
   file.seekg(0, ios::end);
   std::streampos pos = file.tellg();
   cout << "Filesize: " << pos << ", number of Employees in the file: " << pos / sizeof(Employee) << endl;
   while (showRec(i++, file));
   return 0;
}