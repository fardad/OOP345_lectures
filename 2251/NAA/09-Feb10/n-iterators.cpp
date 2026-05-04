#include <iostream>
#include <vector>
using namespace std;
/*


Container<type>::iterator itName;

vector<Employee>::interator ei;

*/


int main( ) {
   vector<int> numbers = { 10, 20, 30 };
   for ( vector<int>::iterator it = numbers.begin( ); it != numbers.end( ); ++it ) {
      cout << *it << " ";  // Dereference the iterator to access the value
   }
   return 0;
}