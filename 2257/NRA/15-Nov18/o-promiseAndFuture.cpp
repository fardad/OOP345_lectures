#include <iostream>
#include <thread>
#include <future>

using namespace std;

using ull = unsigned long long;

void sum_range(promise<ull> sum_prom, ull beg, ull end) {
    ull total = 0;
    for (ull i = beg; i <= end; ++i) {
        total += i;
    }
    sum_prom.set_value(total);
}

int main() {
    ull beg = 0;
    ull end = 1'231'231'231ULL;   // just to show the literal style

    promise<ull> sumPromise1;
    future<ull> sumFuture1 = sumPromise1.get_future();

    promise<ull> sumPromise2;
    future<ull> sumFuture2 = sumPromise2.get_future();

    // move the promises into the threads
    thread t1(sum_range, move(sumPromise1), beg, end / 2);
    thread t2(sum_range, move(sumPromise2), end / 2 + 1, end);

    cout << "Math is being done!\n";

    // get() blocks until each thread sets its promise
    ull total = sumFuture1.get() + sumFuture2.get();
    cout << "The sum is: " << total << '\n';
    cout << "Done!\n";

    t1.join();
    t2.join();

    return 0;
}
