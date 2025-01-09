#include <memory>

class A;

class B {
public:
   std::weak_ptr<A> a;
};

class A {
public:
   std::shared_ptr<B> b;
};

int main( ) {
   std::shared_ptr<A> a = std::make_shared<A>( );
   std::shared_ptr<B> b = std::make_shared<B>( );

   a->b = b;
   b->a = a;

   // Now, when a or b goes out of scope, their reference count will decrease
   // and they will be destroyed, preventing the memory leak.
}