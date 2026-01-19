#include <iostream>
#include <string>
using namespace std;
using namespace std;
class printrable {
   int noOfPrints{};
   int value;
public:
   void print( )const {
      int* p = const_cast<int*>(&noOfPrints);
      cout << value << endl;
      (*p)++;
   }
};

void dump( void* address, size_t size ) {
   char* mem = reinterpret_cast<char*>(address);
   for ( size_t i = 0; i < size; i++ ) {
      cout << static_cast<int>( *mem ) << " ";
   }
}

int main( ) {
   int* p;
   double* d;
   d = reinterpret_cast<double*>(p);

   double value;
   dump( &value, sizeof( value ) );

   return 0;
}