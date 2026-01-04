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
   Box& operator=(const Box&) = delete;
   Box& operator=(Box&& other) noexcept {
      if (this != &other) {
         delete m_data;
         m_data = other.m_data;
         other.m_data = nullptr;
      }
      return *this;
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
   cout << "05-Sep19 OOP345 NAA" << endl;
   Box a(42);
   Box b = a;             // copy
   Box c = std::move(a);  // move
   b.show();
   c.show();
   a.show();              // now empty
   b = Box(100);
   b.show();
   c = move(b);
   b.show();
   c.show();
   return 0;
}