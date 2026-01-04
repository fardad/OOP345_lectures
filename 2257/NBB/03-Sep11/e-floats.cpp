// floats.cpp
#include <iostream>
using namespace std;
/*
Number: 0.0001234567
Scientific Notation: 1.234567 × 10⁻⁴

Significant Digits: 1 2 3 4 5 6 7
                    ^^^^^^^^^^^^^  (7 digits total)

Leading zeros only change the exponent (10⁻⁴), not the precision.


*/
int main() {
    float f = 3.14159f;
    double d = 2.718281828;
    long double ld = 1.6180339887L;

    cout << "float: " << f << endl;
    cout << "double: " << d << endl;
    cout << "long double: " << ld << endl;
    return 0;
}