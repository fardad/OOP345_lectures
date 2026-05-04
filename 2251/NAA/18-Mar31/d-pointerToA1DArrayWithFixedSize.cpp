#include <iostream>
using namespace std;


void foo(int (*ptr)[3]) {
   for (size_t i = 0; i < 3; i++) {
      //cout << (*ptr)[i] << " ";
      cout << ptr[0][i] << " ";
   }
   cout << endl;
}


void foo(int (*ptr)[3], size_t size) {
   for (size_t ii = 0; ii < size; ii++) {
      for (size_t i = 0; i < 3; i++) {
         cout << ptr[ii][i] << " ";
      }
      cout << endl;
   }
   cout << endl;
}



int main() {
   cout << "18-Mar31 OOP345 NAA" << endl;

   int arr[4][3] = {
      { 10, 20, 30 },
      { 110, 120, 130 },
      { 210, 220, 230 },
      { 310, 320, 330 }
   };
   int arr2[8][3] = {
      { 10, 20, 30 },
      { 110, 120, 130 },
      { 210, 220, 230 },
      { 310, 320, 330 },
      { 10, 20, 30 },
      { 110, 120, 130 },
      { 210, 220, 230 },
      { 310, 320, 330 }
   };
   
   int arr3[1][3] = { {1000, 2000, 3000} };

   int ar1d[3] = { 123, 234, 345 };
   int ar4_1d[4] = { 123, 234, 345, 456 };

   cout << "ar1d: " << reinterpret_cast<unsigned long long>(ar1d) << endl;
   cout << "&ar1d: " << reinterpret_cast<unsigned long long>(&ar1d) << endl;
   cout << "ar1d+1: " << reinterpret_cast<unsigned long long>(ar1d + 1) << endl;
   cout << "&ar1d+1: " << reinterpret_cast<unsigned long long>(&ar1d +1) << endl;


   foo(&ar1d);
   //foo(&ar4_1d); //error, size does not match

   foo(arr3);

   foo(arr, 4);
   foo(arr2, 8);

   return 0;
}