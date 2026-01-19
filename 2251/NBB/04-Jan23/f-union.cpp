#include <iostream>
using namespace std;
union Zipcod {
   int zip;
   char code[6];
};
class Address {
   char streeAddress[41];
   char city[21];
   Zipcod zc;

public:
};


int main( ) {
   Zipcod a;
   memcpy( a.code, "L4H2W3", 6 );
   a.zip = 123456;
   cout << reinterpret_cast<unsigned long long>(&a.code[0]) << endl;
   cout << reinterpret_cast<unsigned long long>(&a.zip) << endl;
   return 0;
}