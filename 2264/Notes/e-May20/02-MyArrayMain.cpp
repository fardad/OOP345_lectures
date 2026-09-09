
#include <iostream>
#include "MyArray.h"
using namespace std;
using namespace seneca;
int main() {
    MyArray<int> arr;
    for (int i = 0; i < 5; i++)
        arr[i] = i * i;

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
