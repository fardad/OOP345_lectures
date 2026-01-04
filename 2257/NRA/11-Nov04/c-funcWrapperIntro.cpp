// intro_range.cpp - Basic STL range demo
#include <iostream>
#include <vector>
#include <functional>
#include <string>
void prn(const std::string& str) {
    std::cout << str;
}

int main() {
    std::function<void(const std::string& )> fw;
    fw = prn;
    fw("hello");
    return 0;
}