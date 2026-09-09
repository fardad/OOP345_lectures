
#include <iostream>
#include <utility>
#include <string>
#include "IntArray.h"
using namespace std;
using namespace seneca;
void prnArray(string name, IntArray a) {
    cout << name << ":\n";
    for (size_t i = 0;i < a.size();i++) {
        cout << a[i];
        if (i != a.size() - 1) cout << ", ";
    }
    cout << endl;
}
// As practice, write a function that recives series of integers from the console and 
// returns it as an IntArray to the caller function

IntArray getInts();

int main() {
    IntArray I{ 5 }, J{ 20 };
    prnArray("I", I); // prnArray(IntArray a = I)
    for (int i = 1;i < 10;i++) {
        I[i - 1] = i * 10;
    }
    prnArray("I", I);
    prnArray("J", J);
    J = move(I);
    cout << "Moving I to J" << endl;
    prnArray("I", I);
    prnArray("J", J);
   // J = getInts();
    return 0;
}