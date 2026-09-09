#include <iostream>
using namespace std;
typedef unsigned long long int ullint;
ullint* p; // pointer to ullint

typedef unsigned long long int* ullint_ptr;
ullint_ptr p1, p2; // simpler than: unsigned long long int* p1, *p2;
typedef int* iptr;
int main() {
    int* a, b; // a is poihter b is not
    iptr i, j; // i and j are both pointers
    int x = 42;
    int* p = nullptr;
    p = &x;     // pointer to int

    cout << "Value of x: " << x << endl;
    cout << "Pointer p points to: " << *p << endl; // dereference
    return 0;
}