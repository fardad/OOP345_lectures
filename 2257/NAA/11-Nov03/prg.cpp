
#include <iostream>

#include <fstream>
using namespace std;
int main() {
   std::ifstream fin("output.txt");
   char text[81];
   int val;
   fin >> text;
   cout << text << endl;
   while (fin) {
      fin >> val;
      cout << val << " ";
   }
   cout << endl;
   fin.clear();
   fin >> text;
   cout << text << endl;
   while (fin) {
      fin >> val;
      cout << val << " - ";
   }
   cout << endl;
   
   return 0;
}