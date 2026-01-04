// func_multi.cpp
#define VOLUME(L, W, H) (L * W * H)

#include <iostream>

int main() {
   double vol = VOLUME(2.0, 3.0, 4.0);
   std::cout << "Volume: " << vol << std::endl;
   return 0;
}