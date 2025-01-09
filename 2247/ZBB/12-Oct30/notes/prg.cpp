#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double v;
   file.seekg(0, ios::end);
   cout << file.tellg()/sizeof(double) << endl;
   file.seekg(sizeof(double) * 2);
   file.read(reinterpret_cast<char*>(&v), sizeof(double));
   cout << v << endl;
   return 0;
}