#include <iostream>
#include <string>
using namespace std;
int main() {
   string str1 = "Hello, World!";          // Direct initialization
   string str2("C++ Programming");        // Constructor initialization
   string str3(5, '*');                   // Initialize with 5 '*'
   cout << str1 << "\n" << str2 << "\n" << str3 << endl;
   return 0;
}