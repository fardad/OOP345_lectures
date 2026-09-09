// file: array_function_pointers.cpp
#include <iostream>
using namespace std;

template <typename T>
bool ascending(T a, T b) { return a > b; }

template <typename T>
bool descending(T a, T b) { return a < b; }

template <typename T>
void sort(T* a, int n, bool (*comp)(T, T)) {
   for (int i = n - 1; i > 0; i--)
      for (int j = 0; j < i; j++)
         if (comp(a[j], a[j + 1]))
            swap(a[j], a[j + 1]);
}

template <typename T>
void display(T* a, int n) {
   for (int i = 0; i < n; i++) cout << a[i] << " ";
   cout << endl;
}

int main() {
   int arr[] = { 1, 5, 2, 3, 6, 7, 2 };
   int n = sizeof arr / sizeof(int);

   bool (*criterion[2])(int, int) = { ascending, descending };

   for (int i = 0; i < 2; i++) {
      sort(arr, n, criterion[i]);
      display(arr, n);
   }
   return 0;
}