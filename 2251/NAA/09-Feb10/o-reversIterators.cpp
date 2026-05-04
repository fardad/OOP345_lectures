#include <iostream>
#include <vector>
using namespace std;

int main( ) {
   vector<int> numbers = { 10, 20, 30 };
   for ( auto it = numbers.rbegin( ); it != numbers.rend( ); ++it ) {
      cout << *it << " ";  // Output: 30 20 10
   }
   return 0;
}