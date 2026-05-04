#include <iostream>
#include <memory>
using namespace std;


struct Coord {
   int m_x, m_y;
   Coord(int x, int y) :m_x(x), m_y(y) {}
};

void main() {
   unique_ptr<int> ptr(new int);
   unique_ptr<int> ptr3(new int{ 3456 });
   unique_ptr<Coord> C(new Coord(10, 20));
   cout << "Enter an integer\n> ";
   cin >> *ptr;
   cout << "You entered " << *ptr << endl;
   cout << C->m_x << endl;
   cout << C->m_y << endl;
   unique_ptr<int> ptr2 = move(ptr);
   cout << *ptr2 << endl;
   ptr3 = move(ptr2);
   cout << *ptr3 << endl;
}