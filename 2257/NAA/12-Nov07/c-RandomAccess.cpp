#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
?: g or p
seek?(streampos value) value is positive
seek?(streamoff value, from where)
value is pos or neg
from where: ios::beg, ios::end, ios::cur

streampos tell?();

*/

int main() {
   ifstream file("nums.bin", ios::binary);
   double v;
   file.seekg(0, ios::end);// (offset, ios::beg, ios::cur, ios::end)
   cout << "file size: " << file.tellg() << " bytes" << endl;
   cout << file.tellg() / sizeof(double) << " doubles in the file!" << endl;
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