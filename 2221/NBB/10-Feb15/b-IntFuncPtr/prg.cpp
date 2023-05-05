#include <iostream>
using namespace std;
#include "Int.h"
bool validateAge(int val, string& errorMessage) {
   bool res = false;
   if (val < 19) {
      errorMessage = "Too young to drink!, next please: ";
   }
   else if (val > 100) {
      errorMessage = "This doesn't seem like a valid age value, please try again: ";
   }
   else {
      res = true;
   }
   return res;
}
bool validMark(int val, string& errorMessage) {
   bool res = true;
   if (val < 0 || val >100) {
      errorMessage = "Invalid Mark value, [0<=mark<=100]: ";
      res = false;
   }
   return res;
}


int main() {
   Int anyValue;
   Int val(0, validateAge);
   cout << "Any int number: ";
   cin >> anyValue;
   cout << "Your value: " << anyValue << endl;
   cout << "Age please: ";
   cin >> val;
   cout << "Good you are " << val << " years old, what would you like to drink?" << endl;
   cout << "................................." << endl;
   val.set(validMark);
   cout << "Enter the mark: ";
   cin >> val;
   cout << "Your mark is: " << val << endl;
   return 0;
}