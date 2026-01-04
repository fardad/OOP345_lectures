#include <iostream>
using namespace std;

bool isAdult(int num) {
   return num >= 18 && num <= 65;
}
bool validNoOfStudents(int num) {
   return num >= 10 && num <= 35;
}
int getInt(bool (*isValid)(int));

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
int getInt(bool (*isValid)(int)) {
   int num;
   bool done = false;
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
         else if (isValid(num)) {
            done = true;
         }
         else {
            cout << "Invlid value, try again...\n> ";
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}