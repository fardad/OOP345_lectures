#include <iostream>
#include <string>
using namespace std;
int main() {
   cout << "OOP345 NBB - Feb 09" << endl;
   string str1 = "Hello, World!";          // Direct initialization
   string str2("C++ Programming");        // Constructor initialization
   string str3(5, '*');                   // Initialize with 5 '*'
   cout << str1 << "\n" << str2 << "\n" << str3 << endl;

   return 0;
}