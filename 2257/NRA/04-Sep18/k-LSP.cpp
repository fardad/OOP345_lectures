// liskov_bad.cpp
#include <iostream>
using namespace std;

class Rectangle {
   double width{};
   double height{};
public:
   virtual void setWidth(double w) { width = w; }
   virtual void setHeight(double h) { height = h; }
   double getWidth() const { return width; }
   double getHeight() const { return height; }
};

class Square : public Rectangle {
public:
   void setWidth(double s) override {
      Rectangle::setWidth(s);
      Rectangle::setHeight(s); // forces equal sides
   }
   void setHeight(double s) override {
      Rectangle::setWidth(s);
      Rectangle::setHeight(s); // forces equal sides
   }
};

void set(Rectangle& r) {
   r.setWidth(3);
   r.setHeight(4);
   if (r.getWidth() * r.getHeight() != 12)
      cerr << "* area isn't 12 *" << endl;
}

int main() {
   Rectangle r;
   r.setWidth(10);
   r.setHeight(30);
   cout << "Rectangle: " << r.getWidth() << " x " << r.getHeight() << endl;

   Square s;
   s.setWidth(5);
   cout << "Square: " << s.getWidth() << " x " << s.getHeight() << endl;

   set(r); // works
   set(s); // fails LSP
   return 0;
}