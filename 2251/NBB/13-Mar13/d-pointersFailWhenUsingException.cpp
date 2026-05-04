// this doesn't compile!!!!!!!!!!!!!!!!!!!!!!
#include <iostream>
using namespace std;

int foo( const char* str ) {
   try {
      char* copy = new char[strlen( str ) + 1];
      // do something with copy
      if (/*something went wrong*/ ) {
         throw "somthing when wrong";
      }
      delete[] copy;
   }
   catch ( ... ) {
      delete[] copy;
      throw "continue the exception"
   }
}


int main( ) {
   cout << "13-Mar13-OOP345NBB" << endl;
   char name[50] = "Fardad";
   try {
      foo( name );
   }
   catch ( ... ) {
      // whatever....
   }
   return 0;
}
