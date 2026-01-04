#include <iostream>
using namespace std;

int g = 10; // global scope, external linkage

int main() {
   int x = 5; // local scope
   cout << g + x << endl;
}