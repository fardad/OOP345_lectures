#include <iostream>
#include <string>
using namespace std;

bool validAge(int age) {
   return age >= 7 && age <= 100;
}

bool validNoOfStudentsInClass(int num) {
   return num >= 5 && num <= 35;
}
/*

bool (*isValid)(int)


*/

int getInt(string message, bool (*isValid)(int)) {
   int num{};
   bool done = false;
   do {
      cin >> num;
      if (cin.fail()) {
         cin.clear();
         cout << "Invlid integer, try again: ";
      }
      else {
         // Only the following logic should change to make the validation work for different types of value
         //if ((*isValid)(num)) { // C syntax
         if (isValid(num)) { // C++ syntax
            done = true;
         }
         else {
            cout << message;
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}


int main() {
   cout << "Enter your age: ";
   int age = getInt("Invalid Age, try again: ", validAge);
   cout << "age: " << age << endl;
   cout << "Enter number of students in class: ";
   int num = getInt("Invlid Number of students in class: ", validNoOfStudentsInClass);
   cout << "Number of students: " << num << endl;
   return 0;
}