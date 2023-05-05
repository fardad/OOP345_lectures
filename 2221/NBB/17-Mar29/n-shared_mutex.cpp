#include <iostream>
#include <thread>
#include <vector>
#include <shared_mutex>
using namespace std;
void add(unsigned long& value, shared_mutex& key) {
   for (size_t i = 0; i < 100; i++) {
      unique_lock<shared_mutex> lg(key); // RAII, Resource Acquisition Is Intialization
      value++;  // going to the washroom
   }
}


void query(unsigned long& valueOut, unsigned long& value, shared_mutex& key) {
   shared_lock<shared_mutex> sl(key);
   valueOut = value * 100;
}