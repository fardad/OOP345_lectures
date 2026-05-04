#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main( ) {
   ifstream file( "nums.bin" , ios::binary);
   double v;
   while ( file.read( reinterpret_cast<char*>(&v), sizeof( v ))) {
      cout << v << " ";
   }
   cout << endl;
   file.clear( );
   file.seekg( sizeof( v ) * 2 );
   file.read( reinterpret_cast<char*>(&v), sizeof( v ) );
   cout << "3rd one: " << v << endl;
   file.seekg( 0, ios::end );
   std::streampos pos = file.tellg( );
   cout << "file size: " << static_cast<size_t>(pos) << endl;
   file.seekg( pos - static_cast<streampos>(sizeof( v )) );
   file.read( (char*)&v, sizeof( v ) );
   cout << "last One: " << v << endl;
   file.seekg( 0, ios::beg );
   file.read( (char*)&v, sizeof( v ) );
   cout << "first One: " << v << endl;
   file.seekg( -static_cast<streamoff>(sizeof( v )), ios::end );
   file.read( (char*)&v, sizeof( v ) );
   cout << "again last One: " << v << endl;

   return 0;
}