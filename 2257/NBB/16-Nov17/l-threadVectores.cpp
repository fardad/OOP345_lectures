#include <thread>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using clk = chrono::steady_clock;

void chars(int& n, clk::time_point sec, char ch) {
    for (n = 0; clk::now() < sec; ++n) {
        cout << ch;
    }
}

int main() {
    int tx{}, ty{}, tz{};
    clk::time_point Seconds = clk::now() + chrono::seconds(3);

    vector<thread> thrds;
    thrds.emplace_back(chars, ref(tx), Seconds, '^');
    thrds.emplace_back(chars, ref(ty), Seconds, '-');
    thrds.emplace_back(chars, ref(tz), Seconds, '_');

    for (auto& t : thrds) {
        t.join();
    }

    cout << endl;
    cout << "tX Printed " << tx << " characters!" << endl;
    cout << "tY Printed " << ty << " characters!" << endl;
    cout << "tZ Printed " << tz << " characters!" << endl;

    return 0;
}
