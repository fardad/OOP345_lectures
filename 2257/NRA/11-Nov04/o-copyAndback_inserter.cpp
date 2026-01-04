// copy.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>  // For std::back_inserter

int main() {
    std::vector<int> src = { 1, 2, 3, 4, 5 };
    std::vector<int> dest(5);

    // Full copy
    std::copy(src.begin(), src.end(), dest.begin());
    std::cout << "Copied: ";
    for (int n : dest) std::cout << n << " ";
    std::cout << std::endl;

    // Copy if even (to new vector)
    std::vector<int> evens;
    std::copy_if(src.begin(), src.end(), std::back_inserter(evens), [](int n) { return n % 2 == 0; });
    std::cout << "Evens: ";
    for (int n : evens) std::cout << n << " ";
    std::cout << std::endl;
    return 0;
}