#include <iostream>
#include <string>
using namespace std;
int getInt() {
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
         if (num >= 2 && num <= 36) {
            done = true;
         }
         else {
            cout << "invlid age, try again: ";
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}


int main() {
   cout << "Enter your age: ";
   int age = getInt();
   cout << "age: " << age << endl;
   return 0;
}