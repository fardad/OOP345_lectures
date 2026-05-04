
#include <iostream>
#include <utility>
using namespace std;

class Box {
   int* data{};
public:
   Box(int v) : data(new int(v)) {}
   // copy constructor
   Box(const Box& other) : data(new int(*other.data)) {}
   Box(Box&& other) :data{ other.data } {
      other.data = nullptr;
   }
   Box& operator=(const Box& other) {
      if (this != &other) {
         delete data;
         data = nullptr;
         if (other.data) {
            data = new int(*other.data);
         }
      }
      return *this;
   }
   Box& operator=(Box&& other) {
      if (this != &other) {
         delete data;
         data = other.data;
         other.data = nullptr;
      }
      return *this;
   }
   ~Box() { delete data; }
   void show() const {
      if (data) cout << *data << endl;
      else cout << "empty" << endl;
   }
};



int main() {
   cout << "OOP345NBB - Jan 16" << endl;
   Box a(42);
   Box b = a;     // copy
   a.show();
   Box c = std::move(a);  // move
   b.show();
   c.show();
   a.show();
   c = move(b);

   b.show();
   c.show();
   a.show();
   a = Box(2000);
   a.show();
   return 0;
}