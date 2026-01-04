#include <iostream>
#include <string>
#include <string_view>
using namespace std;

int main() {
   string text = "OOP345 Rocks!";
   string_view view = text;

   cout << "Before: " << view << endl;

   text = "Updated!Updated!Updated!Updated!";
   cout << "After: " << view << endl; // this is unpredictable
   return 0;
}