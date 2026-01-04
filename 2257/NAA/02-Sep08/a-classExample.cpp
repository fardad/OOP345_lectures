// oop_example.cpp
#include <iostream>
using namespace std;

class Car {
   int speed;
public:
   Car(int s = 0) : speed(s) {}
   void accelerate(int value) { speed += value; }
   void show() const { cout << "Speed: " << speed << " km/h\n"; }
};

int main() {
   Car c(50);
   c.accelerate(20);
   c.show(); // Speed: 70 km/h
   return 0/
}