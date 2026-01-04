// bind.cpp
#include <iostream>
#include <functional>

double divide(double x, double y) { return x / y; }

int main() {

	auto functor = std::bind(divide, 100, 4);
	std::cout << "Quotient = " << functor() << std::endl;
	return 0;
}