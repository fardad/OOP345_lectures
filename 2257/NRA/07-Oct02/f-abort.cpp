#include <iostream>
using namespace std;

int main() {
   cout << "About to abort!" << endl;
   abort(); // no cleanup
   return 0;
}