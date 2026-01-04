#include <iostream>
using namespace std;
#include "Int.h"

int main() {
   Int mark(0, 
      [](int val, string& str) {
         str = "Invalid Mark value, [0<=mark<=100]: "; 
         return val >= 0 && val <= 100; 
      }
   );

   Int age(0,
      [](int val, string& messageOut) {
         bool res = false;
         static int noOfValidations = 0;
         if (val < 19) {
            messageOut = "Too young to drink!, next please (No of tries, " + to_string(noOfValidations) + "): ";
            noOfValidations++;
         }
         else if (val > 100) {
            messageOut = "This doesn't seem like a valid age value\nplease try again (No of tries, " + to_string(noOfValidations) + "): ";
            noOfValidations++;
         }
         else {
            res = true;
            noOfValidations = 0;
         }
         return res;
      }
   );

   cout << "Age please: ";
   cin >> age;
   cout << "Good you are " << age << " years old, what would you like to drink?" << endl;
   cout << "................................." << endl;
   cout << "Enter the mark: ";
   cin >> mark;
   cout << "Your mark is: " << mark << endl;
   return 0;
}