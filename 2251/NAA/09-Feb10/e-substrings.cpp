#include <iostream>
#include <string>
using namespace std;
int main( ) {
   string text = "Programming in C++";
   size_t pos = text.find( "C++" );
   if ( pos != string::npos ) {
      cout << "'C++' found at position: " << pos << endl;
   }
   return 0;
}