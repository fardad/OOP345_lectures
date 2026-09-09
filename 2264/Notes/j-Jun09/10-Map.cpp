#include <iostream>
#include <map>
using namespace std;
//Use Case: Use map when you need to store data in key-value pairs with efficient lookups.
int main() {
   map<string, int> phoneBook;

   // Add key-value pairs
   phoneBook["Alice"] = 1234;
   phoneBook["Bob"] = 5678;

   // Access values
   cout << "Alice's number: " << phoneBook["Alice"] << endl;

   // Print all key-value pairs
   cout << "Phone Book: " << endl;
   for (const auto& entry : phoneBook) {
      cout << entry.first << ": " << entry.second << endl;
   }
   return 0;
}