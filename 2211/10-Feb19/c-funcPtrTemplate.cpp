#include <iostream>
using namespace std;
template <typename T>
bool ascending(T a, T b) {
   return a > b;
}
template <typename T>
bool descending(T a, T b) {
   return a < b;
}

// bubble sort
template <typename T>
void sort(T* arr, int n, bool(*comp)(T, T)) {
   for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
         if (comp(arr[j], arr[j + 1])) {
            T temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

template <typename T>
void display(T* a, int n) {
   for (int i = 0; i < n; i++)
      cout << a[i] << endl;
}

int main() {
   int a[] = { 1, 5, 2, 3, 6, 7, 2 };

   cout << "-----------------------------" << endl;
   sort(a, 7, ascending<int>);
   display(a, 7);
   cout << "-----------------------------" << endl;
   sort(a, 7, descending<int>);
   display(a, 7);
}