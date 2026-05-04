#include <iostream>
using namespace std;
union ZC {
   int zip;
   char code[6];
};
struct Address {
   char streeAddress[41];
   char city[21];
   ZC zipcode;
};


int main( ) {
   Address A;
   cout << sizeof( ZC ) << endl;
   cout << alignof(ZC)  << endl;
   cout << reinterpret_cast<unsigned long long>(&A.zipcode.code[0]) << endl;
   cout << reinterpret_cast<unsigned long long>(&A.zipcode.zip) << endl;
   return 0;
}