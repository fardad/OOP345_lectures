#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
   cout << "04Sep15 OOP345NBB" << endl;
   for (int i = 0; i < argc; i++) {
      cout << (i + 1) << ": " << argv[i] << endl;
   }
   return 0;
}