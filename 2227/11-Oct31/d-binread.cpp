#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double v;
   file.read((char*)&v, sizeof(v));
   cout << v << endl;
   file.seekg(sizeof(v) * 3);
   file.read((char*)&v, sizeof(v));
   cout << v << endl;
   return 0;
}
