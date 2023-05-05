#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"
using namespace std;
bool showRec(int row, ifstream& F) {
   Employee E;
   F.clear();
   F.seekg(0);
   int i;
   for (i = 0; F && i < row; i++) {
      F >> E;
   }
   if (F) {
      cout << i << ": " << E << endl;
   }
   else {
      cout << "End of file was reached!" << endl;
   }
   return bool(F);
}
int main() {
   Employee E;
   int i = 0;
   ifstream file("employee.txt");
   while (file >> E) {
      cout << (++i) << ": " << E << endl;
   }
   cout << "===============================" << endl;
   showRec(10, file);
   showRec(100, file);
   file.clear();
   i = 0;
   // very bad way going through the file
   while (showRec(++i, file));
   return 0;
}