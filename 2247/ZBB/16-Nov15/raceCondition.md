A **race condition** occurs when two or more threads (or processes) access shared data at the same time, and at least one of them tries to modify the data. Because the threads are "racing" to perform their actions, the outcome can vary, depending on the exact order in which the threads execute. This can lead to **unexpected behavior** and **bugs** that are hard to reproduce and debug.

### Simple Explanation:
Imagine you and a friend are each adding $1 to your shared bank account at the same time. Without a race condition, your account balance would be correctly updated by $2 after both additions. But if both of you check the balance, add $1, and save the result without knowing the other has also added, you might end up with only $1 added to the account rather than $2.

### Simple Code Example in C++

```cpp
#include <iostream>
#include <thread>

int shared_counter = 0;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        ++shared_counter; // increment shared counter
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << shared_counter << std::endl;
    return 0;
}
```

#### Explanation:
- **Expected Output:** Since both `t1` and `t2` add 1000 to `shared_counter`, the final value should be `2000`.
- **Actual Output:** Due to the race condition, the result might be less than `2000` because `t1` and `t2` might read and modify `shared_counter` simultaneously. For example:
  - `t1` reads `shared_counter` as `10`.
  - Before `t1` writes back, `t2` reads `shared_counter` as `10`.
  - Both `t1` and `t2` write `11` as the new value, so only one increment actually happens.

### Fixing Race Conditions
To prevent race conditions, **synchronization mechanisms** like **mutexes** are used to ensure only one thread modifies shared data at a time.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

int shared_counter = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // only one thread can enter here at a time
        ++shared_counter;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << shared_counter << std::endl;
    return 0;
}
```

With the `std::mutex` in place, only one thread at a time can access `shared_counter`, eliminating the race condition.