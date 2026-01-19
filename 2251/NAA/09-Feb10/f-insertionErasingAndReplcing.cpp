#include <iostream>
#include <string>
using namespace std;
int main( ) {
   string sentence = "I love C++!";
   sentence.insert( 7, "learning " );   // Insert at position 7
   cout << sentence << endl;          // Output: I love learning C++!

   sentence.erase( 2, 5 );              // Remove 5 characters from position 2
   cout << sentence << endl;          

   sentence.replace( 2, 3, "enjoy" );   // Replace "C++" with "enjoy"
   cout << sentence << endl;         
   return 0;
}