#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   fstream file("nums.bin", ios::in | ios::out | ios::binary);
   double d;
   while (file.read((char*)&d, sizeof(d))) {
      cout << d << " ";
   }
   cout << endl;
   file.clear();
   // std::streampos is the type of address in a file stream
   // this means it will skip two doubles and overwrite the third;
   file.seekp(std::streampos(2) * sizeof(double));
   d = 1111.11;

   file.write((const char*)&d, sizeof(d));
   file.seekg(0);
   while (file.read((char*)&d, sizeof(d))) {
      cout << d << " ";
   }
   cout << endl;
   return 0;
}