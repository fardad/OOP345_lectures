// initializers.cpp
#include <iostream>
using namespace std;
//void print(int a[]) {
//    for (int e : a) {
//        cout << e;
//    }
//    cout << "|" << endl;
//}
int main() {
    int a[]{ 1, 2, 3 };
    int b[5]{ 1, 2, 3 }; // rest zero-initialized
    int c[5]{};        // all elements 0

    for (int e : a) {
        cout << e;    
    }
    cout << "|" << endl;
    for (int& e : b) {
        cout << e; 
        e = 1000;
    }
    cout << "|" << endl;
    for (int e : c) cout << e; cout << "|" << endl;
    return 0;
}