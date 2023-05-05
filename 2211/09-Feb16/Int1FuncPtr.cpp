#include <iostream>
#include <string>
#include "Int.h"
using namespace std;

bool validAge(int val, string& errorMessage) {
   bool res = false;
   if (val < 19) {
      errorMessage = "Too young to drink!";
   }
   else if(val > 110){
      errorMessage = "Seems like a fake age, please enter again: ";
   }
   else {
      res = true;
      errorMessage = "";
   }
   return res;
}

bool validMark(int val, string& errorMessage) {
   bool res = true;
   if (val < 0 || val >100) {
      errorMessage = "Invalid Mark value, [0<=mark<=100]: ";
      res = false;
   }
   else {
      errorMessage = "";
   }
   return res;
}

int main() {
   Int val(0, validAge);
   cout << "Age please: ";
   cin >> val;
   cout << val << "is a valid age!" << endl;
   val.set(validMark);
   cout << "Mark: ";
   cin >> val;
   cout << "Your mark is: " << val << endl;
   return 0;
}