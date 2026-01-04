#include <iostream>
using namespace std;

int i = 100; // global

int main() {
   int i;
   cout << "Enter i: ";
   cin >> i;

   if (i < 0) {
      int i = 4;  // shadows outer i
      cout << i << endl;
   }
   else {
      int i = -4; // shadows outer i
      cout << i << endl;
   }
   cout << ::i << endl; // global i
}