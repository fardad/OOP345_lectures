#include <iostream>
#include <string>
#include <string_view>
using namespace std;

void printString( string_view sv ) {
   cout << "Received: " << sv << endl;
}

int main( ) {
   string str = "Hello, string_view!";
   printString( str );                        // No copy made

   string_view sv = str.substr( 7 );          // Create a view of "string_view!"
   cout << "Substring view: " << sv << endl;

   const char* rawStr = "C-style string";
   string_view rawView( rawStr );             // View a raw string
   cout << "Raw string view: " << rawView << endl;
   size_t pos = rawView.find( "str" );
   cout << pos << endl;

   return 0;
}