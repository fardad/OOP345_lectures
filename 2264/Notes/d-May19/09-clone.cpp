// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual double volume() const = 0;
    virtual Shape* clone() const = 0;   // polymorphic copy
    virtual ~Shape() = default;
};
#endif

// Cube.h
#include "Shape.h"

class Cube : public Shape {
    double len{};
public:
    Cube(double l) : len(l) {}
    double volume() const override { return len * len * len; }
    Shape* clone() const override { return new Cube(*this); }
};

// Sphere.h
#include "Shape.h"

class Sphere : public Shape {
    double rad{};
public:
    Sphere(double r) : rad(r) {}
    double volume() const override { return 4.18879 * rad * rad * rad; }
    Shape* clone() const override { return new Sphere(*this); }
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
    Shape* shape = new Sphere(1.0);
    Shape* clone = shape->clone();

    displayVolume(shape);
    displayVolume(clone);

    delete shape;
    delete clone;
    return 0;
}