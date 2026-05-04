#include <iostream>
#include <thread>

using namespace std;

const int CNT = 2'000'000;

void work(int& counter) {
   for (int i = 0; i < CNT; i++) {
      counter++;     // race on counter
   }
}

int main() {
   int counter = 0;
   thread a(work, ref(counter));
   thread b(work, ref(counter));
   thread c(work, ref(counter));

   a.join();
   b.join();
   c.join();

   cout << "\nExpected: " << CNT * 3 << endl;
   cout << "Actual  : " << counter << endl;
}
