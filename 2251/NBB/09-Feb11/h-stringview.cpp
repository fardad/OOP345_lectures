#include <iostream>
#include <string>
#include <string_view>
using namespace std;

void findWord( string_view text, string_view word ) {
   size_t pos = text.find( word );
   if ( pos != string::npos ) {
      cout << "'" << word << "' found at position: " << pos << endl;
   }
   else {
      cout << "'" << word << "' not found." << endl;
   }
}

int main( ) {
   string paragraph = "C++ programming is powerful and efficient.";
   findWord( paragraph, "powerful" ); // Pass by view (no copy)
   findWord( paragraph, "Python" );

   return 0;
}