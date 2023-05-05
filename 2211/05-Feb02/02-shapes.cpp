#include <iostream>

class Shape {
public:
   virtual double volume() const = 0;
   virtual Shape* clone() const = 0;
};
class Cube : public Shape {
   double len;
public:
   Cube(double);
   double volume() const;
   Shape* clone() const;
};
Cube::Cube(double l) : len{ l } {
}


double Cube::volume() const {
   return len * len * len;
}

Shape* Cube::clone() const {
   return new Cube(*this);
}

class Sphere : public Shape {
   double rad;
public:
   Sphere(double);
   double volume() const;
   Shape* clone() const;
};

Sphere::Sphere(double r) : rad{ r } {
}

double Sphere::volume() const {
   return 4.18879 * rad * rad * rad;
}

Shape* Sphere::clone()const {
   return new Sphere(*this);
}


#include <iostream>

void displayVolume(const Shape* shape) {
   if (shape)
      std::cout << shape->volume() << std::endl;
   else
      std::cout << "error" << std::endl;
}

Shape* select() {
   Shape* shape;
   double x;
   char c;
   std::cout << "s (sphere), c (cube) : ";
   std::cin >> c;
   if (c == 's') {
      std::cout << "dimension : ";
      std::cin >> x;
      shape = new Sphere(x);
   }
   else if (c == 'c') {
      std::cout << "dimension : ";
      std::cin >> x;
      shape = new Cube(x);
   }
   else
      shape = nullptr;
   return shape;
}

int main() {
   Shape* shape = select();
   Shape* clone = shape->clone();
   displayVolume(shape);
   displayVolume(clone);
   delete clone;
   delete shape;
}
// copying is possible
Shape* copy(const Shape& original) {
   Shape* copy = original.clone();
   return copy;
}

