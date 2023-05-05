#include <iostream>
#include <string>
#include "Validation.h"
#include "Int.h"
using namespace std;

int main() {
   ValidAge va;
   ValidMark vm;
   Int val(0, &va);
   cout << "Age please: ";
   cin >> val;
   cout << val << "is a valid age!" << endl;
   val.set(&vm);
   cout << "Mark: ";
   cin >> val;
   cout << "Your mark is: " << val << endl;
   return 0;
}