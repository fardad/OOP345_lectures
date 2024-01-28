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
   while (!file.read((char*)&E, sizeof(Employee)).fail()) {
      cout << ++i << ": " << E << endl;
   }
   cout << "======================" << endl;
   showRec(12, file);
   showRec(22, file);

   return 0;
}