






#include <iostream>

class Shape {
public:
   virtual double volume() const = 0;
};
class Cube : public Shape {
   double len;
public:
   Cube(double);
   double volume() const;
};
Cube::Cube(double l) : len{ l } {
}

double Cube::volume() const {
   return len * len * len;
}

class Sphere : public Shape {
   double rad;
public:
   Sphere(double);
   double volume() const;
};

Sphere::Sphere(double r) : rad{ r } {
}

double Sphere::volume() const {
   return 4.18879 * rad * rad * rad;
}

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
   displayVolume(shape);
   delete shape;
}