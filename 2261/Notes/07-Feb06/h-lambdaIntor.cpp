#include <iostream>
#include <string>
using namespace std;
int getInt(bool (*valid)(int)) {
   int num{};
   bool done = false;
   do {
      cin >> num;
      if (cin.fail()) {
         cin.clear();
         cout << "Unreadable integer, try again...\n> ";
      }
      else {
         if (cin.peek() != '\n') {
            cout << "Please only enter an integer...\n> ";
         }
         else if (valid(num)) {
            done = true;
         }
         else {
            cout << "Invalid, try again\n> ";
         }
      }
      cin.ignore(100000, '\n');
   } while (!done);
   return num;
}


int main() {
   auto validmark = [](int mark)->bool {return mark >= 0 && mark <= 100; };
   
   cout << "Enter a mark\n> ";
   int mark = getInt(validmark);
   cout << "Mark is: " << mark << endl;

   cout << "Enter number of Students\n> ";
   int noOfstds = getInt([](int stno)->bool {return stno >= 5 && stno <= 40; });
   cout << "No of students: " << noOfstds << endl;

   int age = getInt(
      [](int num)->bool {
         bool ret = false;
         if (num < 18) {
            cout << "No Children allowed!";
         }
         else if (num > 65) {
            cout << "No Seniors please...";
         }
         else {
            ret = true;
         }
         return ret;
      }
   );



   return 0;
}