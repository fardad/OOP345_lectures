#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2;

void task1() {
   std::scoped_lock lock(mtx1, mtx2);
   std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
   std::cout << "Task 1 done\n";
}

void task2() {
   std::scoped_lock lock(mtx2, mtx1);
   std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
   std::cout << "Task 2 done\n";
}

int main() {
   std::thread t1(task1);
   std::thread t2(task2);

   t1.join();
   t2.join();
   std::cout << "done" << std::endl;
   return 0;
}