#pragma once
#ifndef SENECA_STACK_H
#define SENECA_STACK_H
namespace seneca {
   template <typename type>
   class Stack;

   template <typename type>
   class Node {
      type m_data;
      Node* m_next;
      Node( const type& data, Node* next ):m_data(data), m_next(next) {}
      friend class Stack<type>;
   };

   template<typename type>
   class Stack {
      Node<type>* m_top{};
   public:
      Stack( ) = default;
      Stack( const Stack<type>& ) = delete;
      Stack<type>& operator=( const Stack<type>& ) = delete;
      Stack( Stack<type>&& ) = delete;
      Stack<type>& operator=( Stack<type>&& ) = delete;

      void push( const type& data ) {
         Node<type>* temp = new Node<type>( data, m_top );
         m_top = temp;
      }
      type pop( ) {
         type ret = m_top->m_data;
         Node<type>* toDel = m_top;
         m_top = m_top->m_next;
         delete toDel;
         return ret;
      }
      bool isEmpty( )const {
         return m_top == nullptr;
      }
      virtual ~Stack( ) {
         while ( !isEmpty( ) ) {
            pop( );
         }
      }

   };


}
#endif