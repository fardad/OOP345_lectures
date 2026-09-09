#include <iostream>
using namespace std;
void hanoi(int n, char from, char to, char aux) {
    if (n != 0) {
        hanoi(n - 1, from, aux, to);
        cout << "Ring(" << n << "): " << from << "->" << to << endl;
        hanoi(n - 1 , aux, to, from);
    }
}

int main() {
    hanoi(5, 'A', 'C', 'B');
    return 0;
}