#include <iostream>
using namespace std;

int main() {
    int x, y;
    x = (y = 5, y + 2);  // evaluates y=5, then y+2
    cout << x << endl;   // 7
    return 0;
}