// reference_wrapper_vector.cpp
#include <iostream>
#include <vector>
#include <functional>

int main() {
	std::vector<double> original(5, 7.5);
	std::vector<double> cpy(original.begin(), original.end());
	std::vector<std::reference_wrapper<double>> refs(original.begin(), original.end());

	// Modify original
	for (auto& e : original) e *= 2;

	// Refs reflect changes
	for (auto e : refs) std::cout << e << " ";
	std::cout << std::endl;

	// Modify through refs
	for (auto& e : refs) e *= 1.5;

	// Original reflects changes
	std::cout << "Original after ref mod: ";
	for (auto val : original) std::cout << val << " ";
	std::cout << std::endl;

	return 0;
}