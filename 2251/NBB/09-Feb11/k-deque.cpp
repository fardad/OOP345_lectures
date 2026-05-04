#include <iostream>
#include <deque>
using namespace std;

int main( ) {
   deque<int> dq = { 20, 30 };

   // Add elements
   dq.push_front( 10 );    // Add to the front
   dq.push_back( 40 );     // Add to the back

   // Remove elements
   dq.pop_front( );       // Remove the first element

   // Access elements
   cout << "First element: " << dq[0] << endl;
   cout << "Final deque: ";
   for ( int num : dq ) {
      cout << num << " ";
   }
   return 0;
}