// func_multi.cpp
#define VOLUME(L, W, H) (L * W * H)

#include <iostream>

int main() {
   double vol = VOLUME(2.0, 3.0, 4.0);
//   double vol = (2.0 * 3.0 * 4.0);
   double l = 123, w = 345, h = 456;
   std::cout << "Volume: " << vol << std::endl;
   std::cout << "Volume: " << VOLUME(l, w, h) << std::endl;
   //std::cout << "Volume: " << (l * w * h) << endl;
   return 0;
}