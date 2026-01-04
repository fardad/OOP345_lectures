//Non-Type Template Parameters
template <typename T, int SIZE = 100>
class Array {
   T a[SIZE];
   T dummy{};
public:
   Array() = default;
   T& operator[](unsigned i) {
      return i < SIZE ? a[i] : dummy;
   }
};


void foo() {
   Array<int, 10> a;

   Array<double> b;
}