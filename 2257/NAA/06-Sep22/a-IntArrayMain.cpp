#include <iostream>
#include "IntArray.h"
using namespace std;
using namespace seneca;

int main() {
   cout << "06-Sep22 OOP345 NAA" << endl;
   IntArray I(3);
   for (int i = 0; i < 5; i++) {
      I[i] = i + 10;
   }
   cout <<"*"<< I << "*"<< endl;
   return 0;
}