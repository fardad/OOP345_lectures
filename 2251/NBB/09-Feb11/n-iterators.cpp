#include <iostream>
#include <vector>
using namespace std;

int main( ) {
   vector<int> numbers = { 10, 20, 30 };
   vector<string>::iterator sit;
   for ( vector<int>::iterator it = numbers.begin( ); it != numbers.end( ); ++it ) {
      cout << *it << " ";  // Dereference the iterator to access the value
   }
   return 0;
}