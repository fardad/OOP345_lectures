#include <iostream>
#include <list>
using namespace std;

int main( ) {
   list<int> numbers = { 10, 20, 30 };    // Create a list with initial values

   // Add elements
   numbers.push_front( 5 );              // Add to the front
   numbers.push_back( 40 );              // Add to the back

   // Insert and remove elements
   auto it = numbers.begin( );          // Iterator to the beginning
   advance( it, 2 );                     // Move the iterator to the 3rd element
   numbers.insert( it, 15 );             // Insert 15 before the 3rd element
   numbers.remove( 20 );                 // Remove all occurrences of 20


   // Print all elements
   cout << "Final list: ";
   for ( int num : numbers ) {
      cout << num << " ";
   }
   return 0;
}