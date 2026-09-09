#include <iostream>
#include <string>
#include "Array.h"
using namespace std;
using namespace seneca;
template <typename type>
void printArray(string label, const Array<type> a) {
    cout << label << ":" << endl << a << endl;
}
int main() {
    Array<double> d(3);
    cout << "double array: " << endl;
    cout << d << endl;
    for (int i = 0; i < 5; i++) {
        d[i] = (i + 1) * .23;
    }
    printArray("doubles", d);
    return 0;
}
