#include <iostream>
#include <cstdlib>
using namespace std;
void clear();

#ifdef __linux__
void clear() {
   system("clear");
}

#else
void clear() {
   system("cls");
}
#endif


int main() {
   for (int i = 1000; i < 10000; i++) {
      cout << "1000" << " ";
   }
   cin.ignore();
   clear();
   return 0; 
}