#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mtx1, mtx2;

void task1() {
   lock_guard<mutex> lock1(mtx1);

   this_thread::sleep_for(chrono::milliseconds(100)); // Simulate work

   lock_guard<mutex> lock2(mtx2); // Waiting for mtx2
   cout << "Task 1 done\n";
}

void task2() {
   lock_guard<mutex> lock2(mtx2);
   this_thread::sleep_for(chrono::milliseconds(100)); // Simulate work
   lock_guard<mutex> lock1(mtx1); // Waiting for mtx1 (deadlock)
   cout << "Task 2 done\n";
}

int main() {
   thread t1(task1);
   thread t2(task2);

   t1.join();
   t2.join();

   return 0;
}