#include <iostream>
#include <string.>
using namespace std;


int main( ) {
   cout << "Jun02 - OOP345 NEE" << endl;
   string firstName = "John";
   string lastName = "Doe";
   string fullName = firstName + " " + lastName;   // Combine strings
   cout << "Full Name: " << fullName << endl;


   fullName.append( " Jr." );                        // Append more text
   cout << fullName << endl; // Output: John Doe Jr.
   return 0;
}