#include <iostream>
using namespace std;

int main() {
    int i = 0;
    if (i != 0 && 10 / i > 1)  // second part not evaluated
        cout << "Won't crash" << endl;
    else
        cout << "Safe!" << endl;
    return 0;
}