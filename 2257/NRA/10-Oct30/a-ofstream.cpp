#include <iostream>
#include <fstream>
using namespace std;
int main() {
   cout << "OOP345NRA Oct 30" << endl;
   ofstream fileout("output.txt");
   fileout << "Hello there I am testing this!" << endl;
   return 0;
}