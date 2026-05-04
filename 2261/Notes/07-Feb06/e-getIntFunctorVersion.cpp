#include <iostream>
#include <string>
using namespace std;
class IntValidation {
protected:
   int m_noOfValidations{};
public:
   virtual bool operator()(int val, string& errMes) = 0;

};

class IsTeen :public IntValidation {
public:
   virtual bool operator()(int val, string& errMes) {
      bool res{};
      if (val < 13 || val >19) {
         errMes = "Only teenagers please\n> ";
      }
      else {
         res = true;
      }
      return res;
   }
};

int getInt(IntValidation& valid) {
   int num{};
   bool done = false;
   string message = "";
   do {
      cin >> num;
      if (cin.fail()) {
         cin.clear();
         cout << "Invlid integer, try again...\n> ";
      }
      else {
         if (cin.peek() != '\n') {
            cout << "Only an integer...\n> ";
         }
         else if (valid(num, message)) {
            done = true;
         }
         else {
            cout << message << "...\n> ";
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}

int main() {
   int age{};
   IsTeen isteen;
   cout << "Age: ";

   age = getInt(isteen);
   return 0;
}