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
   // streamoff type of offset address from a location
   // from: ios::cur, ios::beg, ios::end
   file.seekp(std::streamoff(5) * sizeof(double), ios::cur);
   d = 2222.22;
   file.write((const char*)&d, sizeof(d));
   file.seekp(std::streamoff(-3) * sizeof(double), ios::cur);
   d = 3333.33;
   file.write((const char*)&d, sizeof(d));

   file.seekg(0);
   while (file.read((char*)&d, sizeof(d))) {
      cout << d << " ";
   }
   cout << endl;
   return 0;
}