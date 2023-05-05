#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double d;
   while (file.read((char*)&d, sizeof(d))) {
      cout << d << endl;
   }
   file.clear();
   file.seekg(std::streampos(2 * sizeof(double)));
   file.read((char*)&d, sizeof(d));
   cout << d << endl;
   file.seekg(-2 * std::streamoff(sizeof(double)), ios::cur);
   file.read((char*)&d, sizeof(d));
   cout << d << endl;
   return 0;
}