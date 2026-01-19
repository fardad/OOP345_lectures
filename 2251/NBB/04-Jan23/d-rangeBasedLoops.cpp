#include <iostream>
using namespace std;

//void prnArray(int arr[]) { // cannot do it here, since arr just a pointer and not an array
//   for(auto& e : arr) {
//
//   }
//}


int main( ) {
   int a[]{ 10, 20, 30, 40, 50, 60 };
   for ( int& el : a ) {
      cout << el << " ";
   }
   cout << endl;
   cout << "----------------------------------------" << endl;
   for ( auto& e : a ) {
      cout << e << " ";
      e++;
   }
   cout << endl;
   for ( auto& e : a ) {
      cout << e << " ";
   }
   cout << endl;
   cout << "----------------------------------------" << endl;
   for ( auto e : a ) {
      cout << e << " ";
      e++;
   }
   cout << endl;
   for ( auto& e : a ) {
      cout << e << " ";
   }
   cout << endl;
   return 0;
}