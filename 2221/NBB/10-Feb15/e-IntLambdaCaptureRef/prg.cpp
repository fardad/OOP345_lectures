#include <iostream>
using namespace std;
#include "Int.h"

int main() {
   int tries = 0;
   Int val(
      [&](int val, string& str) {
         str = "Invalid Mark value, [0<=mark<=100]: ";
         tries++;
         return val >= 0 && val <= 100; 
      }
   );

   cout << "Enter the mark: ";
   cin >> val;
   cout << "The mark: " << val << " was entered after " << tries << " tries." <<  endl;
   return 0;
}