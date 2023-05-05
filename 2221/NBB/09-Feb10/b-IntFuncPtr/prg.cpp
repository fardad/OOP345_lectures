#include <iostream>
using namespace std;
// order options
enum class Order {
   ascending, descending
};

// order comparison
class Compare {
   Order order;
public:
   Compare(Order o) : order(o) {
   }
   bool operator()(int& a, int& b) const {
      return order == Order::ascending ? a > b : a < b;
   }
};

void sort(int* a, int n, const Compare& comp) {
   for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
         if (comp(a[j], a[j + 1])) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
         }
      }
   }
}


void display(int* a, int n) {
   for (int i = 0; i < n; i++)
      std::cout << a[i] << ' ';
   std::cout << std::endl;
}

int main() {
   int a[] = { 1, 5, 2, 3, 6, 7, 2 };
   int n = sizeof a / sizeof(int);

   sort(a, n, Compare(Order::ascending));
   display(a, n);

   sort(a, n, Compare(Order::descending));
   display(a, n);
   return 0;
}