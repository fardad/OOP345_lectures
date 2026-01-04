#include <iostream>
#include <fstream>
using namespace std;
int main() {
   char str[81];
   int val;
   cout << "OOP345NBB Oct 30" << endl;
   ifstream filein("output.txt");
   filein.getline(str, 81, '\n');
   cout << str << endl;
   while (filein >> val) {
      cout << val << endl;
   }
   return 0;
}