#include <iostream>
#include <string>
using namespace std;
int main( ) {
   string str1 = "OOP345NBB 09-Feb11";
   cout << str1 << endl;
   string sentence = "I love C++!";
   sentence.insert( 7, "learning " );   // Insert at position 7
   cout << sentence << endl;
   sentence.erase( 2, 14 );              // Remove 14 characters from position 2
   cout << sentence << endl;
   sentence.replace( 2, 3, "enjoy" );    // Replace "C++" with "enjoy"
   cout << sentence << endl;
   return 0;
}