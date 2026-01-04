#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double v;
   file.seekg(0, ios::end);// (offset, ios::beg, ios::cur, ios::end)
   cout << file.tellg() / sizeof(double) << endl;
   file.seekg(sizeof(double) * 2);
   file.read(reinterpret_cast<char*>(&v), sizeof(v));
   if (file) cout << v << " ";
   file.seekg(0);
   file.read(reinterpret_cast<char*>(&v), sizeof(v));
   if (file) cout << v << " ";
   file.seekg(-static_cast<std::streamoff>(sizeof(double))
          , ios::end);
   file.read(reinterpret_cast<char*>(&v), sizeof(v));
   if (file) cout << v << " ";
   cout << endl;
   return 0;
}