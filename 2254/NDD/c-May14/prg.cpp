#include <iostream>
#include <string>
using namespace std;
void print( const string& str ) {
   cout << "Lvalue: " << str << endl;
}
void print( string&& str ) {
   cout << "Rvalue: " << str << endl;
}
int main( ) {
   string hello = "Hello";
   print( hello );
   print( "How are you?" );
   return 0;
}