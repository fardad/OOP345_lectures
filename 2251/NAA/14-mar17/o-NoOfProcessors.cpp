#include <iostream>
#include <thread>

int main( ) {
   unsigned int numThreads = std::thread::hardware_concurrency( );
   std::cout << "Supported concurrent threads: " << numThreads << "\n";
   return 0;
}