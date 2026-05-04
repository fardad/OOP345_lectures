#include <iostream>
using namespace std;
struct Address {
   char streeAddress[41];
   char city[21];
   union {
      int zip;
      char code[6];
   } zipcode{};
};


int main( ) {
   Address A;
   cout << reinterpret_cast<unsigned long long>(&A.zipcode.code[0]) << endl;
   cout << reinterpret_cast<unsigned long long>(&A.zipcode.zip) << endl;
   return 0;
}