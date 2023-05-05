
#include <iostream>
using namespace std;
// 02-sep12   this is a  test
int main(int argc, char* argv[], char* env[]) {
   for (int i = 0; env[i]; i++) {
      cout << (i + 1) << "- " << env[i] << endl;
   }
   return 0;
}
