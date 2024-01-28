#include <iostream>
using namespace std;
void num() {
   static int i = 1000; // stays alive
   i++;
   cout << i << " ";
}

int main() {
   for(int i = 0; i < 5; i++) {
      num();
   }
   return 0;
}