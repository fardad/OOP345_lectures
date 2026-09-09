#include <iostream>
#include <string>
using namespace std;
class IntValidation {
protected:
   int m_noOfValidatins{};
public:
   virtual bool operator()(int val, string& errMes) = 0;
   size_t cnt()const {
      return m_noOfValidatins;
   }
};

class IsAdult :public IntValidation {
public:
   virtual bool operator()(int val, string& errMes) override {
      m_noOfValidatins++;
      errMes = "Not an Adult!";
      return val >= 18;
   }
};

int getInt(IntValidation& isValid);


auto main() -> int {
   IsAdult isAdult();
   cout << "Enter your age:\n> ";
   int age = getInt(isAdult);
   cout << "age: " << age << endl;
   return 0;
}
int getInt(IntValidation& isValid) {
   int num{};
   bool done = false;
   string errmes{};
   do {
      cin >> num;
      if (cin.fail()) {
         cin.clear();
         cout << "Invlid integer, try again...\n> ";
      }
      else {
         if (cin.peek() != '\n') {
            cout << "Only an integer number please...\n> ";
         }
         else if (isValid(num, errmes)) {
            done = true;
         }
         else {
            cout << errmes << "\n> ";
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}
