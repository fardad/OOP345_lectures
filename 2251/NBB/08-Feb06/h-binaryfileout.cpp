#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main( ) {
   cout << "08 - Feb 06, OOP345NBB" << endl;
   ofstream file( "nums.bin", ios::binary );
   vector<double> d{ 10.123456, 11.2343545, 12.334453 , 13.43434 };
   for ( auto& v : d ) {
      file.write( reinterpret_cast<const char*>(&v), sizeof( v ) );
   }

   return 0;
}