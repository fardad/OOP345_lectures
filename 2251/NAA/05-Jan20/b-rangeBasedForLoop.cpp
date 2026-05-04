#include <iostream>
using namespace std;
int main() {
   cout << "OOP244NAA Jan20" << endl;
   int a[]{ 10, 20, 30, 40, 50, 60 };
   for ( int& er : a ) {  // int& er = a[?];
      cout << er << endl;
   }
   for ( int e : a ) {    // int e = a[?];
      cout << e << endl;
   }

   for ( auto& aer : a ) {    // auto& aer = a[?];
      cout << aer << endl;
   }
   return 0;
}