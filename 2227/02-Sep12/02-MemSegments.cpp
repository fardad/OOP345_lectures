#include <iostream>
using namespace std;
int main() {
	int* a;
	int b = 12345;
	a = new int[1000];
	delete[] a;
   return 0;
}
void foo() {
	int x;
	foo();
}