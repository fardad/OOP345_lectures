#include <iostream>
using namespace std;

class Animal {
public:
   void speak() const { cout << "Some sound\n"; }
};

class Dog : public Animal {
public:
   void speak() const { cout << "Woof!\n"; }
};

int main() {
   Dog d;
   d.speak(); // Woof!
}