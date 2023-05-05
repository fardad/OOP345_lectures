#include <iostream>
using namespace std;
#include "Validated.h"
bool validateAge(int val, string& errorMessage) {
   bool res = false;
   errorMessage = "";
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
   errorMessage = "";
   if (val < 0 || val >100) {
      errorMessage = "Invalid Mark value, [0<=mark<=100]: ";
      res = false;
   }
   return res;
}


int main() {
   ValidatedArray<int> anyValue;
   ValidatedArray<double> anyValued;
   size_t i;
   for (i = 0; i < 5; i++) {
      anyValue[size_t(i)] = i + 10;
   }
   for (i = 0; i < 5; i++) {
      cout << anyValue[size_t(i)] << " ";
   }
   cout << endl;
   for (i = 0; i < 5; i++) {
      anyValued[size_t(i)] = i + 10.1234;
   }
   for (i = 0; i < 5; i++) {
      cout << anyValued[size_t(i)] << " ";
   }
   cout << endl;
   return 0;
}