#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
// don't study this!!!! I'll talk about it later.
int main( ) {
   cout << "08 - Feb 06, OOP345NBB" << endl;
   ifstream file( "nums.bin", ios::binary );
   double v;
   file.read( reinterpret_cast<char*>(&v), sizeof( v ) );
   cout << v << endl;
   //file.seekg(address from the begenning of the file);
   file.seekg( sizeof( v ) * 3 );
   file.read( (char*)&v, sizeof( v ) );
   cout << v << endl;
   file.seekg( ios::end, 0 );
   std::streampos pos = file.tellg( ) - (std::streampos)sizeof(v);
   file.read( (char*)&v, sizeof( v ) );
   cout << v << endl;
   return 0;
}