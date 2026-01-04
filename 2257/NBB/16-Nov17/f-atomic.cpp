#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

const int CNT = 2'000'000;

void work(atomic<int>& counter) {
    for (int i = 0; i < CNT; i++) {
        counter++;     // atomic increment (safe)
    }
}

int main() {
    atomic<int> counter{0};

    thread a(work, ref(counter));
    thread b(work, ref(counter));
    thread c(work, ref(counter));

    a.join();
    b.join();
    c.join();

    cout << "\nExpected: " << CNT * 3 << endl;
    cout << "Actual  : " << counter.load() << endl;
}
