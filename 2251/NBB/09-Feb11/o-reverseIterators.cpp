#include <iostream>
#include <vector>
using namespace std;

int main( ) {
   vector<int> numbers = { 10, 20, 30 };
   for ( auto rit = numbers.rbegin( ); rit != numbers.rend( ); ++rit ) {
      cout << *rit << " ";  // Output: 30 20 10
   }
   return 0;
}