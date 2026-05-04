#include <iostream>
#include <string>
using namespace std;
int main( ) {
   string str1 = "OOP345NBB 09-Feb11";
   cout << str1 << endl;
   string sentence = "Learning C++";
   cout << "Length: " << sentence.size( ) << endl;  // Get string length

   sentence.clear( );                               // Clear the string
   if ( sentence.empty( ) ) cout << "String is empty!" << endl;   
   return 0;
}