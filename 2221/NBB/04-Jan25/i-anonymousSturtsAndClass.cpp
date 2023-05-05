#include <iostream>
using namespace std;
struct {
   int x;
   int y;
} coord;

int main() {
   coord.x = 3;
   coord.y = 4;

   auto c = coord;
   cout << c.x << " " << c.y << endl;
   return 0;
}