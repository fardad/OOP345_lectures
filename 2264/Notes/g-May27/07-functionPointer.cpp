#include <iostream>
using namespace std;
void sum(int a, int b) {
    cout << (a + b) << endl;
}

void prod(int a, int b) {
    cout << (a * b) << endl;
}

void nums(int x, int num) {
    for (int i = 0; i < num; i++) {
        cout << x;
    }
    cout << endl;
}
int main() {

    void (*fptr)(int, int)=nullptr;

    int i = 3, j = 10;
    sum(i, j);
    prod(i, j);
    nums(i, j);
    fptr = sum;
    fptr(i, j);
    cout << reinterpret_cast<unsigned long long>(sum) << endl;
    cout << reinterpret_cast<unsigned long long>(fptr) << endl;
    fptr = prod;
    fptr(i, j);
    fptr = nums;
    fptr(i, j);
    return 0;
}