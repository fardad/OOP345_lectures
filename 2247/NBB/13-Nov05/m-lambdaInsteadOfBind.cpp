
#include <iostream>
#include <functional> 
using namespace std;

void greet( const string& name, const string& greeting ) {
   cout << greeting << ", " << name << "!" << endl;
}


int main( ) {
   auto greetJohn = []( const std::string& greeting ) {
      greet( "John", greeting );
      };

   greetJohn( "Hello" );  // Output: Hello, John!

   return 0;
}
