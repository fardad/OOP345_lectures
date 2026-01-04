#include <iostream>
using namespace std;

int main() {
   int* arr[3];
   arr[0] = new int[10];
   arr[1] = new int[20];
   arr[2] = new int[30];


   for (int i = 0; i < 3; i++) delete[] arr[i];


   int** p = new int* [4];
   p[0] = new int[10];
   p[1] = new int[20];
   p[2] = new int[30];
   p[3] = new int[40];

    for (int i = 0; i < 4; i++) delete[] p[i];
   delete[] p;


   return 0;
}