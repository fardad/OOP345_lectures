// locks_demo.cpp
// Compile with:  g++ -std=c++17 -pthread locks_demo.cpp -o locks_demo

#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <chrono>

#define MUTEXED_IO(expr)\
    do {\
        std::lock_guard<std::mutex> lock(io_mtx);\
        expr;\
    } while (false)


using namespace std;
using clk = chrono::steady_clock;

//-----------------------------------------
// 1) lock_guard demo – protect a counter
//-----------------------------------------
mutex lg_mtx;
int lg_counter = 0;

void lg_worker(int loops) {
   for (int i = 0; i < loops; ++i) {
      lock_guard<mutex> guard(lg_mtx);  // lock for this block
      ++lg_counter;                     // critical section
   }
}

void demo_lock_guard() {
   cout << "\n=== lock_guard demo ===\n";

   lg_counter = 0;
   const int loops = 100'000;
   thread t1(lg_worker, loops);
   thread t2(lg_worker, loops);

   t1.join();
   t2.join();

   cout << "Expected: " << loops * 2 << "\n";
   cout << "Actual  : " << lg_counter << "\n";
   cout << "(With lock_guard, they match and no race occurs.)\n";
}

//---------------------------------------------
// 2) unique_lock demo – manual unlock / relock
//---------------------------------------------
mutex ul_mtx;
int ul_counter = 0;

void ul_worker() {
   unique_lock<mutex> lock(ul_mtx);   // locks here

   cout << "\n[unique_lock] Inside critical section...\n";
   ++ul_counter;

   cout << "[unique_lock] Temporarily unlocking...\n";
   lock.unlock();                     // manual unlock

   // do “work” outside the critical section
   this_thread::sleep_for(chrono::milliseconds(100));

   cout << "[unique_lock] Locking again...\n";
   lock.lock();                       // lock again
   ++ul_counter;
   cout << "[unique_lock] Leaving critical section.\n";
}

void demo_unique_lock() {
   cout << "\n=== unique_lock demo ===\n";

   ul_counter = 0;
   thread t(ul_worker);
   t.join();

   cout << "ul_counter should be 2 -> " << ul_counter << "\n";
   cout << "(unique_lock lets us unlock/relock manually.)\n";
}

//----------------------------------------------------
// 3) scoped_lock demo – deadlock-free multi-mutex lock
//----------------------------------------------------
mutex a_mtx, b_mtx;
int a_value = 100;
int b_value = 200;

// BAD pattern (for discussion only, not run):
// lock_guard<mutex> lockA(a_mtx);
// lock_guard<mutex> lockB(b_mtx);
// Another thread that locks in opposite order can deadlock.

void transfer_with_scoped_lock(int amount) {
   scoped_lock sl(a_mtx, b_mtx);  // locks both without deadlock risk
   a_value -= amount;
   b_value += amount;
   cout << "[scoped_lock] Transferred " << amount
      << " from A to B (A=" << a_value << ", B=" << b_value << ")\n";
}

void demo_scoped_lock() {
   cout << "\n=== scoped_lock demo ===\n";

   a_value = 100;
   b_value = 200;

   thread t1(transfer_with_scoped_lock, 10);
   thread t2(transfer_with_scoped_lock, 20);

   t1.join();
   t2.join();

   cout << "Final A: " << a_value << "\n";
   cout << "Final B: " << b_value << "\n";
   cout << "(scoped_lock safely locks multiple mutexes at once.)\n";
}

//---------------------------------------------------
// 4) shared_lock demo – multiple readers, one writer
//---------------------------------------------------
shared_mutex sm;
mutex io_mtx;
int shared_value = 0;

void reader(int id) {
   for (int i = 0; i < 3; ++i) {
      shared_lock<shared_mutex> lock(sm);  // shared (reader) lock
      MUTEXED_IO(cout << "[reader " << id << "] sees value = " << shared_value << "\n";);
      this_thread::sleep_for(chrono::milliseconds(50));
   }
}

void writer(int id) {
   for (int i = 0; i < 3; ++i) {
      unique_lock<shared_mutex> lock(sm);  // exclusive (writer) lock
      ++shared_value;
      MUTEXED_IO(cout << "   [writer " << id << "] increments value to "
         << shared_value << "\n";);
      this_thread::sleep_for(chrono::milliseconds(80));
   }
}

void demo_shared_lock() {
   cout << "\n=== shared_lock demo (shared_mutex) ===\n";

   shared_value = 0;

   thread r1(reader, 1);
   thread r2(reader, 2);
   thread w1(writer, 1);

   r1.join();
   r2.join();
   w1.join();

   cout << "Final shared_value = " << shared_value << "\n";
   cout << "(Readers share the lock; writer gets exclusive access.)\n";
}

//-----------------------------------------
// main – run all demos
//-----------------------------------------
int main() {
   cout << "Locking primitives live demo\n";

  // demo_lock_guard();
   //demo_unique_lock();
  // demo_scoped_lock();
   demo_shared_lock();

   cout << "\nDone.\n";
   return 0;
}
