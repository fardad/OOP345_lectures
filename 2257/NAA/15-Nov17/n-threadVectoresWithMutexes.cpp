#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <vector>

using namespace std;
using clk = chrono::steady_clock;

void chars(int& n, mutex& mx, clk::time_point& sec, char ch) {
    scoped_lock<mutex> lg(mx);                // lock for whole function
    for (n = 0; clk::now() < sec; ++n) {
        cout << ch;
    }
    sec = clk::now() + chrono::seconds(1);    // prepare next thread's window
}

int main() {
    int tx{}, ty{}, tz{};
    clk::time_point Seconds = clk::now() + chrono::seconds(1);
    mutex key;

    // Hold the mutex before starting the threads, so they all block at the start
    key.lock();

    vector<thread> thrds;
    thrds.emplace_back(chars, ref(tx), ref(key), ref(Seconds), '^');
    thrds.emplace_back(chars, ref(ty), ref(key), ref(Seconds), '-');
    thrds.emplace_back(chars, ref(tz), ref(key), ref(Seconds), '_');

    cout << "GO!" << endl;
    key.unlock();   // let exactly one thread run chars()

    for (auto& t : thrds) {
        t.join();
    }

    cout << '\n';
    cout << "tX Printed " << tx << " characters!" << endl;
    cout << "tY Printed " << ty << " characters!" << endl;
    cout << "tZ Printed " << tz << " characters!" << endl;

    return 0;
}
