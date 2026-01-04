#include <iostream>
using namespace std;
void faa( );
void foo( );
int main( ) {
   cout << "OOP345" << endl;
   faa( );
   faa( );
   return 0;
}
void faa( ) {
   static int s = 1;
   s++;
   cout << s << " ";
}
