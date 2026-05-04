#include <iostream>
using namespace std;
void foo(int ptr[], size_t size) {
   for (size_t i = 0; i < size; i++) {
      cout << ptr[i] << " ";
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
   int* ptr = reinterpret_cast<int*>(arr);

   for (size_t i = 0; i < 4; i++){
      foo(arr[i], 3);
   }
   foo(ptr, 12);
   cout << "arr: " << reinterpret_cast<unsigned long long>(arr) << endl;
   cout << "ptr: " << reinterpret_cast<unsigned long long>(ptr) << endl;
   cout << "arr+1: " << reinterpret_cast<unsigned long long>(arr+1) << endl;
   cout << "ptr+1: " << reinterpret_cast<unsigned long long>(ptr+1) << endl;

   return 0;
}