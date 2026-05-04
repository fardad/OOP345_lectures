#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.bin", ios::binary);
   double v;
             // 0 is of type streamoff   
   file.seekg(0, ios::end);// goto end of the file
   //file.seekg(10); // 10 is of type streampos (can not be negative)
   std::streampos s = file.tellg(); // tell me what is your position
   cout << "Size of file: " << s << endl;
   cout << "Number of records in file: " << s / sizeof(v) << endl;
   return 0;
}
