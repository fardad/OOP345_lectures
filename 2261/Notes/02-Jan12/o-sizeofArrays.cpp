#include <iostream>
using namespace std;
struct Rec {
   double a;
   double b;
};
void getName(char name[]) {
   cout << sizeof(name) << endl;
}
int main(int argc, char* argv[], char* env[]) {
   char name[80] = "Fred";
   Rec* r;
   cout << sizeof(name) << endl;
   getName(name);
   return 0;
}