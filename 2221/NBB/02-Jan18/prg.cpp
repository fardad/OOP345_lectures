#include <iostream>
using namespace std;
int main(int argc,char* argv[], char* env[]) {
   int i;
   for ( i = 0; i < argc; i++) {
      cout << (i + 1) << ": " << argv[i] << endl;
   }
   for (i = 0; env[i] != nullptr; i++) {
      cout << (i + 1) << ": " << env[i] << endl;
   }
   return 0;
}