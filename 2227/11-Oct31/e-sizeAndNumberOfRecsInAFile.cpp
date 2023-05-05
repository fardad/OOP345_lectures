#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double v;
   file.seekg(0, ios::end);
   std::streampos s = file.tellg();
   cout << s << endl;
   cout << s / sizeof(double) << endl;
   return 0;
}
