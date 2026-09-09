#include <iostream>
using namespace std;

unsigned factorial(unsigned x) {
    return (x > 2u) ? (x * factorial(x - 1)) : x;
}

int main() {
    cout << factorial(4) << endl;
    return 0;
}