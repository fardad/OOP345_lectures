#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double v;
   file.seekg(0, ios::end);// (offset, ios::beg, ios::cur, ios::end)
   cout << file.tellg() << endl;
   file.seekg(10000);
   cout << file.tellg() << endl;
   if (!file) cout << "File in fail status!" << endl;
   file.read(reinterpret_cast<char*>(&v), sizeof(v));
   if (!file) cout << "File in fail status!" << endl;

   return 0;
}