#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

const int CNT = 2000;

mutex key;

void work(int& counter, char which) {
   for (int i = 0; i < CNT; i++) {
      key.lock();
      counter++;     // race on counter
      cout << which;
      key.unlock();
   }
}

int main() {
   int counter = 0;
   key.lock();
   thread a(work, ref(counter),'a');
   thread b(work, ref(counter), 'b');
   thread c(work, ref(counter), 'c');
   key.unlock();
   a.join();
   b.join();
   c.join();

   cout << "\nExpected: " << CNT * 3 << endl;
   cout << "Actual  : " << counter << endl;
}
