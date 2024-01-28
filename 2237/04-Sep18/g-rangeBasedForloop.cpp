#include <iostream>
using namespace std;


//void prnArray(int arr[]) { // can do it here, since arr is not an array
//   for(auto& e : arr) {
//
//   }
//}


int main() {
   int a[]{ 10, 20, 30, 40, 50, 60 };
   for(int& el : a) {
      cout << unsigned(&el) << ": " << el << endl;
   }
   cout << "----------------------------------------" << endl;
   for(auto& e : a) {
      cout << unsigned(&e) << ": " << e << endl;
   }
   return 0;
}