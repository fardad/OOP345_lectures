#include <iostream>
#include <string>
using namespace std;
int main( ) {
   string sentence = "Learning C++";
   cout << "Length: " << sentence.size( ) << endl;  // Get string length

   sentence.clear( );                               // Clear the string
   if ( sentence.empty( ) ) 
      cout << "String is empty!" << endl;
   return 0;
}