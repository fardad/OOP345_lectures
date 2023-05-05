#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ofstream file("nums.bin", ios::binary);
   vector<double> d = { 10.1, 11.2, 12.3, 13.4, 14.5 , 1.1, 2.2, 3.3, 4.4,5.5,6.6,7.7,8.8,9.9 };
   for (auto& v : d) {
      file.write((const char*)&v, sizeof(v));
   }
   return 0;
}