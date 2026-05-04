#include <iostream>
using namespace std;
void module(); // external linkage 
extern int external; // defined somewhere else

void hanoi(int n, char from, char to, char aux) {
   if (n == 0) return;
   hanoi(n - 1, from, aux, to);
   cout << "(" << n << ")" << "from " << from << " to " << to << endl;
   hanoi(n - 1, aux, to, from);
}

auto main()->int {
   cout << "OOP345 NBB - Feb 02" << endl;
   hanoi(4, 'A', 'B', 'C');
   return 0;
}

