#pragma once
#include <utility>
namespace sdds {
   template <typename T>
   class Stack;

   template <typename T>
   class Node {
      T data{};
      Node<T>* next = nullptr;
      Node(int thedata, Node<T>* thenext = nullptr) :data(thedata), next(thenext) {
      }
      friend class Stack<T>;
   };
   template <typename T>
   class Stack {
      Node<T>* top = nullptr;
      void empty() {
         Node<T>* toDel = nullptr;
         while (top) {
            toDel = top;
            top = top->next;
            delete toDel;
         }
      }
      void mv(Stack<T>&& S) {
         Stack<T> temp;
         while (!S.isEmpty()) {
            temp.push(S.pop());
         }
         while (!temp.isEmpty()) {
            push(temp.pop());
         }
      }
      void copy(const Stack<T>& S) {
         Stack<T> temp;
         Node<T>* cpTop = S.top;
         while (cpTop) {
            temp.push(cpTop->data);
            cpTop = cpTop->next;
         }
         while (!temp.isEmpty()) {
            push(temp.pop());
         }
      }
   public:
      Stack() {
      }
      Stack(Stack<T>&& S) {
         mv(std::move(S));
      }
      Stack(const Stack<T>& S) {
         copy(S);
      }
      Stack<T>& operator=(Stack<T>&& S) {
         if (this != &S) {
            empty();
            mv(std::move(S));
         }
         return *this;
      }
      Stack<T>& operator=(const Stack<T>& S) {
         if (this != &S) {
            empty();
            copy(S);
         }
         return *this;
      }
      void push(T data) {
         top = new Node<T>(data, top);
      }
      bool isEmpty()const {
         return top == nullptr;
      }
      T pop() {
         T data = top->data;
         Node<T>* toDel = top;
         top = top->next;
         delete toDel;
         return data;
      }
      virtual ~Stack() {
         empty();
      }
   };
}