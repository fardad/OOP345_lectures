#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main( ) {
   cout << "i-Jun11 OOP345 NEE" << endl;
   std::vector<std::string> v;
   std::string s = "hello";
   v.push_back( s );        // copy
   v.push_back( "world" );  // temporary string, move
   v.emplace_back( "hello" );           // constructs string in place
   v.emplace_back( 5, 'a' );            // constructs string with 5 'a's
   /*
   supported by:
   vector
   deque
   list
   forward_list  
   */
   /*
   emplace_front
   deque
   list
   forward_list
   
   
   */
   return 0;
}