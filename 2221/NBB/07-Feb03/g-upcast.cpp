#include <iostream>
using namespace std;
class Parent {
public:
   virtual void act() = 0;
};

class Child :public Parent {
public:
   void act();
   void play();
};
class ChildB :public Parent {
public:
   void act();
};

void act(Parent* p) {
   p->act();
   Child* c = dynamic_cast<Child*>(p); // upcasting
   c->play();
}

int main() {
   Child C;
   act(&C);
   return 0;
}
