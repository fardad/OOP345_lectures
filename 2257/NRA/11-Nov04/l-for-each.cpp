// for_each.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    std::for_each(v.begin(), v.end(), [](int& n) { n *= 2; });
    for (int n : v) std::cout << n << " ";
    std::cout << std::endl;
    return 0;
}