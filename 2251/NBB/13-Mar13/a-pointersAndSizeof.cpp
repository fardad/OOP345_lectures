#include <iostream>
using namespace std;
void foo( char name[], int a[] ) {
   cout << "Size in foo!" << endl;
   cout << "sizeof atpr: " << sizeof( a ) << endl;
   cout << "sizeof ntpr: " << sizeof( name ) << endl;
}


int main( ) {
   cout << "13-Mar13-OOP345NBB" << endl;
   char name[50] = "Fardad";
   int a[10] = { 10, 20, 30, 40, 50, 60 };
   char* nptr = name;
   int* aptr = a;

   cout << *name << endl;
   cout << *(name + 3) << endl;
   cout << *nptr << endl;
   cout << *(nptr + 3) << endl;

   cout << *a << endl;
   cout << *(a + 3) << endl;
   cout << *aptr << endl;
   cout << *(aptr + 3) << endl;
   cout << "sizeof atpr: " << sizeof( aptr ) << endl;
   cout << "sizeof ntpr: " << sizeof( nptr ) << endl;
   cout << "sizeof atpr: " << sizeof( a ) << endl;
   cout << "sizeof ntpr: " << sizeof( name ) << endl;
   foo( name, a );
   return 0;
}
