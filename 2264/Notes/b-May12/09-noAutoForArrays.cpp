// auto-error.cpp
#include <iostream>
using namespace std;

int main() {
    auto a[]{ 1, 2, 3 }; // ERROR: array type cannot be deduced
    return 0;
}