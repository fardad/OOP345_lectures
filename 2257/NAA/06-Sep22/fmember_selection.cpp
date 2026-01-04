// member_selection.cpp
#include <iostream>
using namespace std;

struct Point {
   int x;
   int y;
};

int main() {
   Point p{ 1, 2 };
   cout << p.x << "," << p.y << endl; // direct

   Point* ptr = &p;
   cout << ptr->x << "," << ptr->y << endl; // indirect
   return 0;
}