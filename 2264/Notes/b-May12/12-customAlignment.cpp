#include <iostream>
using namespace std;

struct A {
    int n;  // size 4 alignment 4
    char c; // size 1 alignment 1
}; // size 8, alignment 4

struct alignas(16) B {
    int n;  // size 4 alignment 4
    char c; // size 1 alignment 1
}; // size 8, alignment 16

int main() {
    cout << "align of A = " << alignof(A) << endl;
    cout << "align of B = " << alignof(B) << endl;
    return 0;
}