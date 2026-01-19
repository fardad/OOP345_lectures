#include <iostream>
#include <cstring>
using namespace std;
class Name {
   char* m_data{};
   static void strcpy( char* des, const char* src ) {
      int i{};
      for ( i = 0; src[i]; des[i] = src[i++] );
      des[i] = char( 0 );
   }
   static size_t strlen( const char* str ) {
      size_t len = 0;
      while ( str[len] ) len++;
      return len;
   }
   static void alloCopy( char*& data, const char* src ) { // it is needed in name for logic purposes but not an essential 
      // action related to a "Name"
      delete[] data;
      data = new char[strlen( src ) + 1];
      strcpy( data, src );
   }
public:
   Name( const char* name ) {
      alloCopy( m_data, name );
   }
   void display( )const {
      cout << name << endl;
   }
   virtual ~Name( ) {
      delete[] m_data;
   }
};

int main( ) {

   return 0;
}