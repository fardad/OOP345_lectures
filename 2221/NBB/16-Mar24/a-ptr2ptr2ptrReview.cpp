#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main() {
   int*** ar = new int** [3]{ new int* [3] , new int* [4], new int* [5] };
   int*** br = new int** [3]{ new int* [3] , new int* [4], new int* [5] };
   int*** cr = new int** [3]{ new int* [3] , new int* [4], new int* [5] };
   int*** dr = new int** [3]{ new int* [3] , new int* [4], new int* [5] };

   int**** x = new int*** [4]{ ar, br, cr, dr };


   int** a = new int* [3];
   int** b = new int* [4];
   int** c = new int* [5];

   return 0;
}

