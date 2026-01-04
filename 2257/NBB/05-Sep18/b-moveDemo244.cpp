// move_example.cpp
#include <iostream>
#include <utility>
using namespace std;

class Box {
   int* m_data{};
public:
   Box(int v) {
      m_data = new int(v);
   }
   // copy constructor
   Box(const Box& other) {
      m_data = new int;
      *m_data = *other.m_data;
   }
   // move constructor
   Box(Box&& other) noexcept {
      m_data = other.m_data;
      other.m_data = nullptr;
   }
   ~Box() {
      delete m_data;
   }

   void show() const {
      if (m_data) cout << *m_data << endl;
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