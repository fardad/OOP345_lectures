#include <iostream>
using namespace std;

bool isAdult( int num ) {
   return num >= 18 && num <= 65;
}
bool validNoOfStudents( int num ) {
   return num >= 10 && num <= 35;
}
int getint( ) {
   int num{};
   bool done = false;
   do {
      cin >> num;
      if ( cin.fail( ) ) {
         cin.clear( );
         cout << "Unreadable integer, try again...\n> ";
      }
      else {
         if ( cin.peek( ) != '\n' ) {
            cout << "Please only enter an integer...\n> ";
         }
         else if ( isAdult( num ) ) {
            done = true;
         }
         else {
            cout << "no children or seniors...\n> ";
         }
      }
      cin.ignore( 100000, '\n' );
   } while ( !done );
   return num;
}



void sum( int a, int b ) {
   cout << "Sum is " << (a + b) << endl;
}
void prod( int a, int b ) {
   cout << "Product is " << (a * b) << endl;
}
void reduce( int a, int b ) {
   cout << "reduce:  " << (a - b) << endl;
}
void divid( int a, int b ) {
   cout << "divid:  " << (a - b) << endl;
}

int main( void ) {
   int nums[500];



   int* p = nums;

   void (*func)( int, int );
   func = sum;
   func( 10, 20 );

   func = prod;
   func( 20, 30 );

   return 0;
}
