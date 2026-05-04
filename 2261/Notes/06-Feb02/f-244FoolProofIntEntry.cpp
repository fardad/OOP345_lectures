#include <iostream>
using namespace std;
int getInt();
bool isAdult(int age) {
   return age >= 18 && age <= 64;
}
bool validNoOfStudents(int num) {
   return num >= 10 && num <= 35;
}

int main(){
   cout << "OOP345 NBB - Feb 02" << endl;
   cout << "Enter an int\n> ";
   int val = getInt();
   cout << "you entered: " << val << endl;
   return 0;
}

int getInt() {
   int num{};
   bool done{};
   do{
      cin >> num;
      if (cin.fail()) {
         cin.clear();
         cout << "Invalid Integer, retry\n> ";
      }
      else {
         if (cin.peek() != '\n') {
            cout << "only an integer please, retry\n> ";
         }
         else if (isAdult(num)) {
            done = true;
         }
         else {
            cout << "No children or seniors allowed\n> ";
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}