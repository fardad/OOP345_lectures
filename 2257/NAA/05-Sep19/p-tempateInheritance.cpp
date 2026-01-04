// Base template
template <typename T>
class Base {
   T value{};
public:
   void set(const T& v) { value = v; }
   void display() const { std::cout << value << std::endl; }
};

// Derived template
template <typename T>
class Derived : public Base<T> {
public:
   void set(const T& v) { Base<T>::set(v); }
}; T, SIZE>::count = 0;