#include <iostream>
using namespace std;
struct Coord {
   double x, y;
};
void prn( int arr[], int size ) {
   cout << "-------------" << endl;
   cout << sizeof( arr ) << endl;
   cout << "-------------" << endl;
   for ( int i = 0; i < size; i++, cout << arr[i] << endl );
}

int main() {
   int a[10] = { 10,20,30,40,50,60,70 };
   Coord C;
   cout << sizeof( double ) << endl;
   cout << sizeof( Coord ) << endl;
   cout << sizeof( C ) << endl;
   cout << sizeof( a ) << endl;
   prn( a, 10 );
   return 0;
}