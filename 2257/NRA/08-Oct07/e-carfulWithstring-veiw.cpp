#include <iostream>
#include <string>
#include <string_view>
using namespace std;

int main() {
   string text = "OOP345 Rocks!";
   string_view view = text;

   cout << "Before: " << view << endl;

   text = "Updated!Updated!Updated!Updated!Updated!Updated!";
   cout << "After: " << view << endl; // view points to the old data, therefore the result is unknown
   return 0;
}