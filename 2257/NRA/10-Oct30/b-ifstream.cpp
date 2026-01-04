#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
   cout << "OOP345NRA Oct 30" << endl;
   string s;
   ifstream filein("output.txt");
   filein >> s;
   cout << s << endl;
   return 0;
}