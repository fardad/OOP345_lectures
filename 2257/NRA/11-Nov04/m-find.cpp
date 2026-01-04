// find.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    auto it = std::find(v.begin(), v.end(), 3);
    if (it != v.end()) std::cout << "Found: " << *it << std::endl;

    auto it2 = std::find_if(v.begin(), v.end(), [](int n) { return n > 3; });
    if (it2 != v.end()) std::cout << "First >3: " << *it2 << std::endl;
    return 0;
}