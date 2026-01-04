#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

using namespace std;
using clk = chrono::steady_clock;

int main() {
    int tx{}, ty{};
    auto Seconds = clk::now() + chrono::seconds(1);
    mutex key;

    key.lock();   // hold the gate closed before starting threads

    thread tX([&]() {
        lock_guard<mutex> lg(key);               // locks here
        for (tx = 0; clk::now() < Seconds; ++tx) {
            cout << '^';
        }
        Seconds = clk::now() + chrono::seconds(1);
        // lg goes out of scope here -> unlocks automatically
    });

    thread tY([&]() {
        lock_guard<mutex> lg(key);               // waits until key is free
        for (ty = 0; clk::now() < Seconds; ++ty) {
            cout << '_';
        }
        Seconds = clk::now() + chrono::seconds(1);
        // lg goes out of scope here -> unlocks automatically
    });

    cout << "GO!" << endl;
    key.unlock();    // let exactly one thread in

    tX.join();
    tY.join();

    cout << "\n";
    cout << "tX Printed " << tx << " characters!" << endl;
    cout << "ty Printed " << ty << " characters!" << endl;

    return 0;
}
