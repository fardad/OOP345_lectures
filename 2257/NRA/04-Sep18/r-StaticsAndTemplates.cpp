template <typename T, int SIZE>
class Array {
   static unsigned count;
public:
   Array() { ++count; }
   ~Array() { --count; }
   static unsigned getCount() { return count; }
};

template <typename T, int SIZE>
unsigned Array<T, SIZE>::count = 0;
