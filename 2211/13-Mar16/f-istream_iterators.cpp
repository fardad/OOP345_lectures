#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "BEmployee.h"

using namespace std;
int main() {
   int i=0;
   ifstream file("employee.bin", ios::binary);
   istream_iterator<Employee> ii{ file };
   istream_iterator<Employee> eos{};
   vector<Employee> emp{ ii, eos };
   for (auto& e: emp) {
      cout << ++i << ": " << e << endl;
   }
   sort(emp.begin(), emp.end());
   cout << "========================" << endl;
   i = 0;
   for (auto& e : emp) {
      cout << ++i << ": " << e << endl;
   }
   return 0;
}