#include <iostream>
using namespace std;
bool isAdult(int num, string& errMes) {
   bool res{};
   if (!(num >= 18 && num <= 65)) {
      errMes = "No children or seniors permitted!";
   }
   else {
      res = true;
   }
   return res;
}
bool validNoOfStudents(int num, string& errMes) {
   bool res = (num >= 10 && num <= 35);
   if (!res) {
      errMes = "Invalid number of student for a class";
   }
   return res;
}
int getInt(bool (*isValid)(int, string&));
int main() {
   cout << "07-Sep29 OOP345 NBB" << endl;
   cout << "Enter your age: ";
   int age = getInt(isAdult);
   cout << "age: " << age << endl;
   cout << "Enter number of students...\n> ";
   int nos = getInt(validNoOfStudents);
   cout << "No of students in class: " << nos << endl;
   return 0;
}
int getInt(bool (*isValid)(int, string&)) {
   int num{};
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
            cout << "Only enter an Integer, try again...\n> ";
         }
         else if (isValid(num, errMes)) {
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