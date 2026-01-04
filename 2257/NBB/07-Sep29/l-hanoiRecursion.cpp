#include <iostream>
using namespace std;
void hanoi(int n, char A, char C, char B) {
   if (n != 0) {
      hanoi(n - 1, A, B, C);
      cout << "Move ring " << n << " from " << A << " to " << C << endl;
      hanoi(n - 1, B, C, A);
   }
}
int main() {
   hanoi(4, 'A', 'C', 'B');

   return 0;
}