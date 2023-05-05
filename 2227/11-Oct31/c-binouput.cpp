#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ofstream file("nums.bin", ios::binary);
   vector<double> d{ 10.1, 11.232, 12.23 , 13.43 , 14.5, 15.6, 16.7, 17.8 };
   for (auto& v : d) {
      file.write((const char*)&v, sizeof(v));
   }
   return 0;
}