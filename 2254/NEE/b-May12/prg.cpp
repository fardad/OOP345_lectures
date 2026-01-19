#include <iostream>
using namespace std;

int main( ) {
   int x[]{ 10, 20, 30, 40 };
   for ( int& elem : x ) {
      cout << elem << endl;
   }
   return 0;
}