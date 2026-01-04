#include <iostream>
#include <string>
using namespace std;

bool isAdult(int num, string& err) {
   bool valid =  num >= 18 && num <= 65;
   if (!valid) err = "Values between 18 and 65, try again...";
   return valid;
}
bool validNoOfStudents(int num, string& err) {
   bool valid = num >= 10 && num <= 35;
   if (!valid) err = "Number of students must be between 10 and 35, try again...";
   return valid;
}
int getInt(bool (*isValid)(int, string&));

int main() {
   cout << "06-Sep30 OOP345 NRA" << endl;
   cout << "Enter your age: ";
   int age = getInt(isAdult);
   cout << "age: " << age << endl;
   cout << "Enter number of students: ";
   int stno = getInt(validNoOfStudents);
   cout << "Number of students in class: " << stno << endl;
   return 0;
}
int getInt(bool (*isValid)(int, string&)) {
   int num;
   bool done = false;
   string errMes{};
   do {
      cin >> num;
      if (cin.fail()) {
         cin.clear();
         cout << "Invalid Integer, try again...\n> ";
      }
      else {
         if (cin.peek() != '\n') {
            cout << "Only an integer, try again...\n> ";
         }
         //else if (isValid(num, errMes)) {
         else if ( (*isValid)(num, errMes)) { // calling funcPtr C style
            done = true;
         }
         else {
            cout << errMes << "\n> ";
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}