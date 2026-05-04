#include <iostream>
using namespace std;
#include "Validation.h"
#include "Int.h"

int main() {
   ValidAge kidsAge(3, 7);
   ValidAge Adult(19, 100);

   ValidMark vm;
   Int val(0, &kidsAge);
   cout << "Age please: ";
   cin >> val;
   cout << "Good you are " << val << " years old, what juice would you like to drink?" << endl;
   cout << "................................." << endl;
   val.set(&Adult);
   cout << "Age please: ";
   cin >> val;
   cout << "Good you are " << val << " years old, what would you like to drink in Seneca bar?" << endl;
   cout << "................................." << endl;
   val.set(&vm);
   cout << "Enter the mark: ";
   cin >> val;
   cout << "Your mark is: " << val << endl;
   return 0;
}