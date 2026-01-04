#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> data) {
   cout << "In function: value = " << *data << ", use_count = " << data.use_count() << endl;
   *data += 50;
}

int main() {
   auto sp = make_shared<int>(25);  // Preferred: make_shared for efficiency

   cout << "Original: " << *sp << ", use_count = " << sp.use_count() << endl;

   process(sp);  // Shared copy
   cout << "After process: " << *sp << ", use_count = " << sp.use_count() << endl;

   {
      shared_ptr<int> sp2 = sp;  // Another share
      cout << "With sp2: use_count = " << sp.use_count() << endl;
   }  // sp2 dies, count drops
   cout << "After sp2 scope: use_count = " << sp.use_count() << endl;

   // sp dies: delete
   return 0;
}