#include <iostream>
using namespace std;
#include <cstring>

template <typename T>
T maximum(T a, T b) {
    return a > b ? a : b;
}

template <>
const char* maximum<const char*>(const char* a, const char* b) {
    return strcmp(a, b) > 0 ? a : b;
}

int main() {
    cout << maximum(2.3, 4.5) << endl;       // generic version
    cout << maximum("abc", "def") << endl;   // specialization
    cout << maximum<int>(123, 1234.5) << endl; // enforce function temaplate createion with the type of your choice
    return 0;
}