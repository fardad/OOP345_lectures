union mixed {
   int val;
   double dval;
   char cstr[5];
};

#include <iostream>
#include <variant>
using namespace std;

int main() {
   variant<int, double, string> v = 3.14;
   cout << get<double>(v) << endl;

   v = "OOP345";
   cout << get<string>(v) << endl;

   cout << "Current index: " << v.index() << endl;

   try {
      cout << get<int>(v) << endl;
   }
   catch (std::bad_variant_access) {

   }
   return 0;
}