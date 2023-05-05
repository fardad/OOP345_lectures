#include <iostream>
using namespace std; 
void hanoi(int noOfRings, char from_rod, char using_rod, char des_rod);

auto main()->int {  
   hanoi(4, 'A', 'C', 'B');
   return 0;
}

void hanoi(int nor, char rod1, char rod2, char rod3) {
   if (nor == 1) {
      cout << rod1 << "--->" << rod3 << endl;
   }
   else {
      hanoi(nor - 1, rod1, rod3, rod2);
      cout << rod1 << "--->" << rod3 << endl;
      hanoi(nor - 1, rod2, rod1, rod3);
   }
}

