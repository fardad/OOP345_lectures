#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main( ) {
   ofstream file( "nums.txt" );
   vector<double> d{ 10.1, 11.232, 12.23 , 13.43 , 14.5, 15.6, 16.7, 17.8 };
   for ( auto& v : d ) {
      file << v << " ";
   }
   return 0;
}