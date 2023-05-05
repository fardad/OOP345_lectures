#include <iostream>
#include <string>
using namespace std;
// execution not teste!
class IntValidation {
protected:
   int m_noOfValidations{};
public:
   virtual bool operator()(int val, string& errMes) = 0;
};

class ValidAge : public IntValidation {
public:
   bool operator()(int val, string& errMes);
};

class ValidMark : public IntValidation {
public:
   bool operator()(int val, string& errMes);
};

bool ValidAge::operator()(int val, string& errMes) {
   bool res = false;
   if (val < 7) {
      errMes = "Too young to program, no of ties( " + to_string(m_noOfValidations) + " )";
   }
   else if (val > 100) {
      errMes = "Too old to program, no of ties( " + to_string(m_noOfValidations) + " )";
   }
   else {
      res = true;
      errMes = "";
   }
   return res;
}

bool ValidMark::operator()(int val, string& errMes) {
   bool res = false;
   if (val < 0) {
      errMes = "Only positive numbers, no of ties( " + to_string(m_noOfValidations) + " )";
   }
   else if (val > 100) {
      errMes = "value too larg, no of ties( " + to_string(m_noOfValidations) + " )";
   }
   else {
      res = true;
      errMes = "";
   }
   return res;
}
int getInt(IntValidation& valid) {
   int num{};
   bool done = false;
   string message="";
   do {
      cin >> num;
      if (cin.fail()) {
         cin.clear();
         cout << "Invlid integer, try again: ";
      }
      else {
         // Only the following logic should change to make the validation work for different types of value
         //if ((*isValid)(num)) { // C syntax
         if (valid(num, message)) { // C++ syntax
            done = true;
         }
         else {
            cout << message;
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}
int main() {
   ValidMark vmark;
   ValidAge vage;
   int age = getInt(vage);
   int mark = getInt(vmark);
   return 0;
}