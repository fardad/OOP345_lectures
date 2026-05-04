#include <iostream>
using namespace std;
template <typename T>
class uPtr {
   T* m_ptr{};
public:
   uPtr(T* ptr=nullptr) :m_ptr(ptr) {};
   uPtr(const uPtr&) = delete;
   void operator=(const uPtr&) = delete;
   uPtr(uPtr&& other)noexcept {
      m_ptr = other.m_ptr;
      other.m_ptr = nullptr;
   }
   uPtr& operator=(uPtr&& other) noexcept {
      if (this != &other) {
         delete m_ptr;
         m_ptr = other.m_ptr;
         other.m_ptr = nullptr;
      }
      return *this;
   }
   ~uPtr() {
      delete m_ptr;
   }
   T& operator*() {
      return *m_ptr;
   }
   T* operator->() {
      return m_ptr;
   }
};

struct Coord {
   int m_x, m_y;
   Coord(int x, int y) :m_x(x), m_y(y) {}
};

void main() {
   uPtr<int> ptr = new int;
   uPtr<int> ptr3 = new int{ 3456 };
   uPtr<Coord> C = new Coord(10, 20);
   cout << "Enter an integer\n> ";
   cin >> *ptr;
   cout << "You entered " << *ptr << endl;
   cout << C->m_x << endl;
   cout << C->m_y << endl;
   uPtr<int> ptr2 = move(ptr);
   cout << *ptr2 << endl;
   ptr3 = move(ptr2);
   cout << *ptr3 << endl;
}