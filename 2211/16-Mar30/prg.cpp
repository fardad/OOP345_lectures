#include <iostream>
using namespace std;
int main() {

   int*** p;
   p = new int** [2];
   p[0] = new int* [3];
   p[0][1] = new int[20];
   p[0][2] = new int[5];
   p[0][3] = new int[40];



   return 0;
}