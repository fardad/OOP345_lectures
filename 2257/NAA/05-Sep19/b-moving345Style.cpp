// move_example.cpp
#include <iostream>
#include <utility>
using namespace std;

class Box {
   int* data;
public:
   Box(int v) : data(new int(v)) {}
   // copy constructor
   Box(const Box& other) : data(new int(*other.data)) {}
   // move constructor
   Box(Box&& other) : data(other.data) { other.data = nullptr; }
   ~Box() { delete data; }

   void show() const {
      if (data) cout << *data << endl;
      else cout << "empty" << endl;
   }
};

int main() {
   Box a(42);
   Box b = a;             // copy
   Box c = std::move(a);  // move
   b.show();
   c.show();
   a.show();              // now empty
   return 0;
}