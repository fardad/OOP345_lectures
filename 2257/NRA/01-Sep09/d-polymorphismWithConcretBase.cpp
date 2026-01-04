#include <iostream>
using namespace std;

class Animal { // concret base
public:
   virtual void speak() const { cout << "Some sound\n"; }
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
   Animal* a1 = new Dog();
   Animal* a2 = new Cat();

   a1->speak(); // Woof!
   a2->speak(); // Meow!

   delete a1;
   delete a2;
}