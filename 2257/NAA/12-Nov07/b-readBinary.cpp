#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double v;
   while (file) {
      file.read(reinterpret_cast<char*>(&v), sizeof(v));
      if (file) cout << v << " ";
      else
         cout <<endl<< "End of file!" << endl;
   }
   cout << endl;
   return 0;
}