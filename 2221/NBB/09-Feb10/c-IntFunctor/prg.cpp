#include <iostream>
using namespace std;
#include "Validation.h"
#include "Int.h"

int main() {
   ValidAge va;
   ValidMark vm;
   Int val(0, &va);
   cout << "Age please: ";
   cin >> val;
   if (val)
      cout << "Good you are " << val << " years old, what would you like to drink?" << endl;
   else
      cout << "Too many tries, get out of here!!!" << endl;
   cout << "................................." << endl;
   val.set(&vm);
   cout << "Enter the mark: ";
   cin >> val;
   cout << "Your mark is: " << val << endl;
   return 0;
}