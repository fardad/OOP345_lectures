#include <iostream>
#include <fstream>
#include <vector>
#include "BEmployee.h"
using namespace std;
int main() {
    ifstream file("employee2.bin", ios::binary);
    Employee E;
    file.seekg(sizeof(E) * 3);
    file.read(reinterpret_cast<char*>(&E), sizeof(E));
    cout << E << endl;
    file.seekg(-static_cast<streamoff>(sizeof(E)), ios::end);
    file.read(reinterpret_cast<char*>(&E), sizeof(E));
    cout << E << endl;
    return 0;
} 