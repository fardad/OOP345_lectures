#include <iostream>
#include <fstream>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double d;
   while (file.read((char*)&d, sizeof(d))) {
      cout << d << endl;
      file.seekg(1000 * sizeof(double));
      if (file.fail())  // seeking will not fail, but reading will
         cout << "seekg failed" << endl;
   }
   return 0;
}