// intro_range.cpp - Basic STL range demo
#include <iostream>
#include <functional>
using namespace std;
int main() {
    long l = 1234;
    reference_wrapper<long> lrw=l;
    lrw++;
    cout << l << endl;
    return 0;
}