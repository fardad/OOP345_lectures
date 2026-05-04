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

   int arr[3] = { 10, 20, 30 };
   int* ptr = arr;

   foo(arr, 3);
   foo(ptr, 3);

   return 0;
}