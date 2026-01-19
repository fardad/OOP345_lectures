#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Name {
   char* m_data{};
   static void alloCopy( char*& data, const char* src ) { // it is needed in name for logic purposes but not an essential 
      // action related to a "Name"
      delete[] data;
      data = new char[strlen( src ) + 1];
      strcpy( data, src );
   }
public:
   Name( const char* name ) {
      alloCopy( m_data, name );
         // alloCopy(char*& data = m_data, const char* src = name);
   }
   void display( )const {
      cout << m_data << endl;
   }
};
void allocate( int*& nums, size_t size ) {
   nums = new int[size];
}

int main( int argc, char* argv[], char* env[] ) {
   int* n{};
   allocate( n, 30 ); // allocate(int* nums = n, size_t size = 30);
   for ( int i = 0; i < 30; i++ ) {
      n[i] = i;
   }
   delete[] n;
   return 0;
}