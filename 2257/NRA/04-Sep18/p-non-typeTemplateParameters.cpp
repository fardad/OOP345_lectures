//Non - Type Template Parameters
template <typename T, int SIZE>
class Array {
   T a[SIZE];
   T dummy{};
public:
   Array() = default;
   T& operator[](unsigned i) {
      return i < SIZE ? a[i] : dummy;
   }
};

int main() {
   Array<double, 100>;
   return 0;
}