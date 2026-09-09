#include <iostream>
#include <string>
using namespace std;
int main() {
   string firstName = "John";
   string lastName = "Doe";
   string fullName = firstName + " " + lastName;   // Combine strings
   cout << "Full Name: " << fullName << endl;

   fullName.append(" Jr.");                        // Append more text
   cout << fullName << endl; // Output: John Doe Jr.
   string word = "Apple";
   cout << word[0] << endl;       // Output: A
   word[0] = 'a';                 // Modify the first character
   cout << word << endl;          // Output: apple
   cout << word.at(2) << endl;    // Output: p (safe access, checks bounds)

   string sentence = "Learning C++";
   cout << "Length: " << sentence.size() << endl;  // Get string length

   sentence.clear();                               // Clear the string
   if (sentence.empty()) cout << "String is empty!" << endl;
   return 0;
}