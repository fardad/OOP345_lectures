#include <iostream>
#include <vector>
#include <algorithm>

int main( ) {
   std::vector<int> nums = { 1, 2, 3, 4, 5 };
   std::vector<int> res( nums.size( ) );
   std::transform( nums.begin( ), nums.end( ), res.begin( ), []( int n ) { return n * 2; } );// doubles nums into res
   std::transform( nums.begin( ), nums.end( ), nums.begin( ), []( int n ) { return n * 3; } ); //tirpples nums

   
   for ( int n : nums )
      std::cout << n << " ";
   return 0;
}