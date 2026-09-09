#include <iostream>
#include <string>
using namespace std;
int main() {
   string text = "Programming in C++";
   size_t pos = text.find("C++");
   if (pos != string::npos) {
      cout << "'C++' found at position: " << pos << endl;
   }
   string sentence = "I love C++!";
   sentence.insert(7, "learning ");   // Insert at position 7
   cout << sentence << endl;          // Output: I love learning C++!

   sentence.erase(2, 14);              // Remove 5 characters from position 2
   cout << sentence << endl;          // Output: I C++!

   sentence.replace(2, 3, "enjoy");   // Replace "C++" with "enjoy"
   cout << sentence << endl;          // Output: I enjoy!
   return 0;
}