#include <iostream>
using namespace std;
class Coord {
   int m_x, m_y;
public:
   Coord(int x, int y) :m_y{ y } {
      m_x = x;
   }
};
int main() {
   int a = 5;
   int b{ 5 };
   int d = { 5 };
   int e{};
   int f[400]{};
   double g[4]{ 1,2.0,3.4 };
   Coord C{ 10, 50 };
   return 0;
}