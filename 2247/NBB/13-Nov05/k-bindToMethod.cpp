
#include <iostream>
#include <functional> 
using namespace std;

class Printer {
public:
   void printMessage( const string& message ) {
      cout << "Message: " << message << endl;
   }
};

int main( ) {
   Printer prn;

   // Create a function object that binds a member function of the Printer class
   auto boundPrint = bind( &Printer::printMessage, &prn, placeholders::_1 );

   // Call the bound function with an argument
   boundPrint( "Hello from bind!" );  // Output: Message: Hello from bind!

   return 0;
}
