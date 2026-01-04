#include <iostream>
#include <fstream>
using namespace std;
int main() {
   cout << "OOP345NBB Oct 30" << endl;
   ofstream fileOut("output.txt");
   fileOut << "OOP345NBB Oct 30" << endl;
   for (int i = 0; i < 100; i++) {
      fileOut << i << " ";
   }
   return 0;
}