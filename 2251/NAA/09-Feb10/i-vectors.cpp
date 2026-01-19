#include <iostream>
#include <vector>
using namespace std;

int main( ) {
   vector<int> numbers = { 10, 20, 30 };   // Create a vector with initial values

   // Add elements
   numbers.push_back( 40 );                // Add at the end
   numbers.push_back( 50 );

   // Access and modify
   numbers[1] = 25;                      // Modify the second element
   cout << "Third element: " << numbers[2] << endl;

   // Insert and remove elements (expensive)
   numbers.insert( numbers.begin( ) + 2, 15 );  // Insert 15 at index 2
   numbers.erase( numbers.begin( ) + 1 );       // Remove the second element

   // Print all elements
   cout << "Final vector: ";
   for ( int num : numbers ) {
      cout << num << " ";
   }
   return 0;
}