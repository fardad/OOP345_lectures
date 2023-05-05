#include <string>
using namespace std;
#include "validation.h"
auto ValidAge::operator()(int val, string& messageOut)->bool {
   bool res = false;
   if (val < 19) {
      messageOut = "Too young to drink!, next please (No of tries, " + to_string(noOfValidations) + "): ";
      noOfValidations++;
   }
   else if (val > 100) {
      messageOut = "This doesn't seem like a valid age value\nplease try again (No of tries, " + to_string(noOfValidations) + "): ";
      noOfValidations++;
   }
   else {
      res = true;
      noOfValidations = 0;
   }
   return res;
}

auto ValidMark::operator()(int val, string& messageOut)->bool {
   bool res = true;
   if (val < 0 || val >100) {
      messageOut = "Invalid Mark value, [0<=mark<=100] (No of tries, " + to_string(noOfValidations) + "): ";
      noOfValidations++;
      res = false;
   }
   else {
      noOfValidations = 0;
   }
   return res;
}

int Validation::tries() const {
    return noOfValidations;
}
