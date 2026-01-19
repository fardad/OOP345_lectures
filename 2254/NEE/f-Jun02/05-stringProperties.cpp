#include <iostream>
#include <string.>
using namespace std;


int main( ) {
   cout << "Jun02 - OOP345 NEE" << endl;
   string sentence = "Learning C++";
   cout << "Length: " << sentence.size( ) << endl;  // Get string length
   sentence.clear( );                               // Clear the string
   if ( sentence.empty( ) )
      cout << "String is empty!" << endl;
   return 0;
}