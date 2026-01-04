#include <iostream>
#include <fstream>
#include "BEmployee.h"
using namespace std;

int main() {
   ifstream file("bemployee.bin", ios::binary);
   Employee v;
   file.seekg(0, ios::end);// (offset, ios::beg, ios::cur, ios::end)
   cout << "file size: " << file.tellg() << " bytes" << endl;
   cout << file.tellg() / sizeof(v) << " employees in the file!" << endl;
   file.seekg(sizeof(v) * 2);
   file.read(reinterpret_cast<char*>(&v), sizeof(v));
   if (file) cout << v << endl;
   file.seekg(0);
   file.read(reinterpret_cast<char*>(&v), sizeof(v));
   if (file) cout << v << endl;
   file.seekg(-static_cast<std::streamoff>(sizeof(v))
      , ios::end);
   file.read(reinterpret_cast<char*>(&v), sizeof(v));
   if (file) cout << v << endl;
   cout << endl;
   return 0;
}