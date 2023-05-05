#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ofstream file("nums.bin", ios::binary);
   vector<double> d = { 10.1, 11.2, 12.3, 13.4, 14.5 };
   for (auto& v : d) {
      file.write((const char*)&v, sizeof(v));
   }
   return 0;
}