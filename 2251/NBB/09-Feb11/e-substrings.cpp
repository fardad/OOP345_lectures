#include <iostream>
#include <string>
using namespace std;
int main( ) {
   string str1 = "OOP345NBB 09-Feb11";
   cout << str1 << endl;
   string text = "Programming in C++";
   size_t pos = text.find( "C++" );
   cout << text.length( ) << " " << text.size( ) << endl;
   if ( pos != string::npos ) {
      cout << text << endl;
      cout << "'C++' found at position: " << pos << endl;
   }   
   return 0;
}