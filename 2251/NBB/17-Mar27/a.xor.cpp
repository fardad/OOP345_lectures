#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
/*
  0  0000
  1  0001
  2  0010
  3  0011
  4  0100
  5  0101
  6  0110
  7  0111
  8  1000
  9  1001
A 10 1010
B 11 1011
C 12 1100
D 13 1101
E 14 1110
F 15 1111
*/

void bits(int val) {
   unsigned int m = 1 << (sizeof(int) * 8 - 1);
   int cnt = 1;
   while (m) {
      cout << !!(m & val);
      m >>= 1;
      if (cnt++ == 8) {
         cout << " ";
         cnt = 1;
      }
   }
   cout << endl;
}

void swap(int& a, int& b) {
   a = a ^ b;
   b = a ^ b;
   a = a ^ b;
}

int main() {
   cout << "17-Mar27 OOP345 NBB" << endl;
   int D = 20;
   int K = 1234567;
   int E;
   E = D ^ K;

   cout <<"E: " << E << endl;

   D = E ^ K;

   cout << "D:" << D << endl;

   cout << "D: " << D << endl;
   cout << "K: " << K << endl;


   swap(D, K);

   cout << "D: " << D << endl;
   cout << "K: " << K << endl;


   return 0; 
}