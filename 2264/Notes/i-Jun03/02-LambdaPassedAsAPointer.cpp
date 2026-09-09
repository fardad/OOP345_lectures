#include <iostream>
using namespace std;
int getint(bool (*valid)(int)) {
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
            cout << ", try again\n> ";
         }
      }
      cin.ignore(100000, '\n');
   } while (!done);
   return num;
}
int main() {
   std::cout << "OOP345 NAA - Jun03" << endl;
   int val = 24;
   int age = getint([](int val)->bool {return val >= 18 && val <= 65; });
   int test{};
   auto validate = [=]()->bool {return test > 0;  };

   return 0;
}