#include <iostream>
#include <thread>
#include <future>
using namespace std;

int main() {
   promise<int> p;

   future<int> f = p.get_future();

   p.set_value(10);


   if(f.valid()) cout << f.get() << endl;
   if (f.valid()) cout << f.get() << endl;


   return 0;
}