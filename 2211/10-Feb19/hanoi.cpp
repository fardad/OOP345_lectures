#include <iostream>
using namespace std;
void hanoi(int n, char from_rod, char using_rod, char to_rod);


int main(void) {
   hanoi(4, 'A','C','B');
   return 0;
}

void hanoi(int n, char rod_1, char rod_2, char rod_3) {
   static int row = 1;
   if (n == 1) {
      cout << row++ << ": " << rod_1 << " --> " << rod_3 << endl;
   }
   else {
      hanoi(n - 1, rod_1, rod_3, rod_2);
      cout << row++ << ": " << rod_1 << " --> " << rod_3 << endl;
      hanoi(n - 1, rod_2, rod_1, rod_3);

   }
}



