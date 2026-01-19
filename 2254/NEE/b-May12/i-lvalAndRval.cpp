#include <iostream>
using namespace std;

void printRef( const std::string& s ) {
   std::cout << "Lvalue reference: " << s << '\n';
}

void printRef( std::string&& s ) {
   std::cout << "Rvalue reference: " << s << '\n';
}

int main( ) {
   std::string name = "Seneca";

   printRef( name );          // lvalue: binds to const std::string&
   printRef( "Polytechnic" ); // rvalue: binds to std::string&&
   return 0;
}