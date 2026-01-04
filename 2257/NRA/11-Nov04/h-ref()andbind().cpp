// bind.cpp
#include <iostream>
#include <functional>

void decrement(int& x, int& y) { --x; --y; }

int main() {
	int a = 50, b = 30;
	auto functor = std::bind(decrement, std::ref(a), b);
	functor();
	std::cout << "a: " << a << ", b:" << b << std::endl;
	return 0;
}