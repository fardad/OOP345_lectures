#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double d{};
   while (file.read((char*)&d, sizeof(d))) {
      cout << d << " ";
   }
   return 0;
}