#include <iostream>
using namespace std;

int main( ) {
   auto hello = []( ) { return "Hello there!"; };
   cout << hello( ) << endl;
   return 0;
}
