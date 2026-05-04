#include <iostream>
#include <fstream>
#include <vector>
#include "DEmployee.h"
using namespace std;
int main() {
   ifstream file("d_employee.bin", ios::binary);
   ifstream name("d_name.bin", ios::binary);
   Employee E;
   while (E.read(file, name)) {
      cout << E << endl;
   }
   return 0;
}
