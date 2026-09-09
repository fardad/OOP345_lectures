// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual double volume() const = 0;  // pure virtual
    virtual ~Shape() = default;         // always good practice
};

#endif

// Cube.h
#include "Shape.h"

class Cube : public Shape {
    double len{};
public:
    Cube(double l) : len(l) {}
    double volume() const override { return len * len * len; }
};

// Sphere.h
#include "Shape.h"

class Sphere : public Shape {
    double rad{};
public:
    Sphere(double r) : rad(r) {}
    double volume() const override { return 4.18879 * rad * rad * rad; }
};

// main.cpp
#include <iostream>
#include "Cube.h"
#include "Sphere.h"
using namespace std;

void displayVolume(const Shape* shape) {
    if (shape)
        cout << shape->volume() << endl;
    else
        cerr << "ERROR!" << endl;
}

int main() {
    Shape* s1 = new Cube(2.0);
    Shape* s2 = new Sphere(1.0);

    displayVolume(s1); // Calls Cube::volume()
    displayVolume(s2); // Calls Sphere::volume()

    delete s1;
    delete s2;
    return 0;
}