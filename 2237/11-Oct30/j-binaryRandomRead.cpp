#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double v;
   file.read((char*)&v, sizeof(v));
   cout << v << endl;
   //file.seekg(address from the begenning of the file);
   file.seekg(sizeof(v) * 3); 
   file.read((char*)&v, sizeof(v));
   cout << v << endl;
   file.seekg(ios::end, 0);
   std::streampos pos = file.tellg();
   file.seekg(pos - sizef(v));
   file.read((char*)&v, sizeof(v));
   cout << v << endl;
   return 0;
}