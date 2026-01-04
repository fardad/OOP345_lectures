#include <iostream>
using namespace std;
void faa() {
   static int s = 1;
   s++;
   cout << s << " ";
}

int main() {
   cout << "OOP345NRA 01-Sep09" << endl;
   faa();
   faa();
   faa();
   return 0;
}