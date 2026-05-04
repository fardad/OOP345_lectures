#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main( ) {
   ifstream file( "nums.bin", ios::binary );
   double v;
   file.seekg( 0, ios::end );
   std::streampos s = file.tellg( );
   cout <<"Size of file: " << s << endl;
   cout <<"Number of records in file: " <<  s / sizeof( double ) << endl;
   return 0;
}
