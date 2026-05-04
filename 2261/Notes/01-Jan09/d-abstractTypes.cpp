// polymorphism.cpp
#include <iostream>
using namespace std;

class Animal {
public:
   virtual void speak() const = 0;
};

class Dog : public Animal {
public:
   void speak() const override { cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
   void speak() const override { cout << "Meow!\n"; }
};

int main() {
   //Animal* a0 = new Animal(); // error
   Animal* a1 = new Dog();
   Animal* a2 = new Cat();
   a0->speak();; // some sound
   a1->speak(); // Woof!
   a2->speak(); // Meow!
   //delete a0;
   delete a1;
   delete a2;
}