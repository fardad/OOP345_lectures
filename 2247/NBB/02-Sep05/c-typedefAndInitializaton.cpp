#include <iostream>
using namespace std;
void faa( );
void foo( );
int main( ) {
   cout << "OOP345 02-Sep05" << endl;
   faa( );
   faa( );
   return 0;
}
void faa( ) {
   int s = 1;
   s++;
   cout << s << " ";
}

void foo( ) {
   int a = 10;
   while ( a-- ) {
      cout << a << " ";
   }
   cout << endl;
}