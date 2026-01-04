// class_static.cpp
#include <iostream>
using namespace std;

class Shape {
public:
   virtual double volume() const = 0;
   virtual Shape* clone() const = 0;   // polymorphic copy
   virtual ~Shape() = default;
};

class Cube : public Shape {
   double len{};
public:
   Cube(double l) : len(l) {}
   double volume() const override { return len * len * len; }
   Shape* clone() const override { return new Cube(*this); }
};

class Sphere : public Shape {
   double rad{};
public:
   Sphere(double r) : rad(r) {}
   double volume() const override { return 4.18879 * rad * rad * rad; }
   Shape* clone() const override { return new Sphere(*this); }
};



void displayVolume(const Shape* shape) {
   Shape* s = shape->clone();
   if (shape)
      cout << s->volume() << endl;
   else
      cerr << "ERROR!" << endl;
   delete s;
}


int main() {
   Shape* shape = new Sphere(1.0);
   Shape* shape2 = new Cube(1.0);
   Shape* clone = shape->clone();

   displayVolume(shape);
   displayVolume(shape2);
   displayVolume(clone);

   delete shape;
   delete shape2;
   delete clone;
   return 0;
}