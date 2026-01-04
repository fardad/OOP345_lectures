#include <iostream>
using namespace std;


int getInt(bool (*isValid)(int));
int main() {
   cout << "07-Sep29 OOP345 NAA" << endl;
   cout << "Enter your age: ";
   int age = getInt([](int num) {return num >= 16 && num <= 65; });
   cout << "age: " << age << endl;
   cout << "Enter number of students...\n> ";
   int nos = getInt([](int num) {
      return num >= 10 && num <= 35;
   });
   cout << "No of students in class: " << nos << endl;
   return 0;
}

int getInt(bool (*isValid)(int)) {
   int num{};
   bool done = false;
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
         else if (isValid(num)) {
            done = true;
         }
         else {
            cout << "Invlid value...\n> ";
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}