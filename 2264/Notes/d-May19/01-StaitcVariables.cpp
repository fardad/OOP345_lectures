#include <iostream>
using namespace std;
void foo() {
    static int i = 10;
    cout << i << endl;
    i++;
}
int main() {
    int i = 100;
    cout << i << endl;
    foo();
    foo();
    foo();
    foo();
    foo();
    cout << i << endl;
    return 0;
}