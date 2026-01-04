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
   catch (bad_variant_access) {
      cout << "last setting was not an int in varant v" << endl;
   }
   return 0;
}