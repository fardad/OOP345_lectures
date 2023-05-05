#include <iostream>
#include <fstream>
#include <vector>
#include "DEmployee.h"
using namespace std;
bool showRec(size_t row, ifstream& F,ifstream& N) {
   Employee E;
   F.clear();
   F.seekg(std::streampos((row - 1) * (sizeof(Employee) + sizeof(std::streampos) + sizeof(size_t))));
   if (E.read(F, N))
      cout << row << ": " << E << endl;
   else
      cout << "Record out of bound!" << endl;
   return F && N;
}
int main() {
   Employee E;
   int i = 0;
   ifstream file("d_employee.bin", ios::binary);
   ifstream name("d_name.bin", ios::binary);
   file.seekg(0, ios::end);
   std::streampos pos = file.tellg();
   cout << pos << " " << pos / (sizeof(Employee) + sizeof(std::streampos) + sizeof(size_t)) << endl;
   file.seekg(0);
   while (E.read(file, name)) {
      cout << ++i << ": " << E << endl;
   }
   cout << "======================" << endl;
   showRec(12, file, name);
   showRec(22, file, name);

   return 0;
}