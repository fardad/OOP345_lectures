#ifndef SDDS_STACK_H__
#define SDDS_STACK_H__
template <typename T>
class Stack;
template <typename T>
class Node {
   Node<T>* m_next = nullptr;
   T m_data;
   Node(T data, Node<T>* next) {
      m_next = next;
      m_data = data;
   }
   friend class Stack<T>;
   ~Node() {
   }
};

template <typename T>
class Stack {
   Node<T>* top{};// setting to null
   int size{};
public:
   Stack<T>& push(T data) {
      top = new Node<T>(data, top);
      size++;
      return *this;
   }
   T pop() {
      T val;
      val = top->m_data;
      Node<T>* todel = top;
      top = top->m_next;
      delete todel;
      size--;
      return val;
   }
   bool isEmtpy() {
      return top == nullptr;
   }
   operator bool() {
      return top != nullptr;
   }
   virtual ~Stack() {
      Node<T>* todel =top;
      while (top != nullptr) {
         top = top->m_next;
         delete todel;
         todel = top;
      }
   }
   size_t depth() {
      return size;
   }
};


#endif // ! SDDS_STACK_H__
