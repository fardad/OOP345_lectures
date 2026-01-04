// string_example.cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
   string s1 = "Hello";
   string s2 = "World";

   s1 += " ";          // append a space
   s1 += s2;           // concatenate
   cout << "s1: " << s1 << endl;

   cout << "Size: " << s1.size() << endl;
   cout << "First letter: " << s1[0] << endl;

   // Substring and search
   string sub = s1.substr(0, 5);
   cout << "Substring: " << sub << endl;

   size_t pos = s1.find("World");
   if (pos != string::npos)
      cout << "'World' starts at index " << pos << endl;

   // Replace a part of the string
   s1.replace(pos, 5, "C++");
   cout << "After replace: " << s1 << endl;

   return 0;
}