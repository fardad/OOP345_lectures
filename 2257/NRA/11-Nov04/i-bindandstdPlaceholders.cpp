// bind.cpp
#include <iostream>
#include <functional>
using namespace std;
void show(int a, int b) {
	cout << a << ", " << b << endl;
}

int main() {
	auto reversed = std::bind(show, std::placeholders::_2, std::placeholders::_1);
	//std::placeholders::_#  "#" refers to the sequence number of the argument 
	// of the function that is beign bound
	reversed(10, 20);   // prints: 20, 10
	return 0;
}