#ifndef SENECA_UNPTR_H
#define SENECA_UNPTR_H
#include <cstddef>  // for nullptr_t

namespace seneca {

   template <typename Type>
   class UnPtr {
      Type* m_ptr{};

      // Delete the owned object
      void cleanup( ) {
         delete m_ptr;
         m_ptr = nullptr;
      }

   public:
      // Construct from raw pointer (takes ownership)
      explicit UnPtr( Type* ptr = nullptr ) : m_ptr( ptr ) { }

      // No copying — exclusive ownership!
      UnPtr( const UnPtr& ) = delete;
      UnPtr& operator=( const UnPtr& ) = delete;

      // Move constructor: steal ownership
      UnPtr( UnPtr&& other ) noexcept
         : m_ptr( other.m_ptr ) {
         other.m_ptr = nullptr;
      }

      // Move assignment: delete old, steal new
      UnPtr& operator=( UnPtr&& other ) noexcept {
         if ( this != &other ) {
            cleanup( );               // delete current
            m_ptr = other.m_ptr;     // steal
            other.m_ptr = nullptr;   // null source
         }
         return *this;
      }

      // Access
      Type& operator*( ) { return *m_ptr; }
      const Type& operator*( ) const { return *m_ptr; }

      Type* operator->( ) { return m_ptr; }
      const Type* operator->( ) const { return m_ptr; }

      Type* get( ) { return m_ptr; }
      const Type* get( ) const { return m_ptr; }

      // Safe null check: if (up)
      explicit operator bool( ) const {
         return m_ptr != nullptr;
      }

      // Compare with nullptr
      bool operator==( std::nullptr_t ) const { return m_ptr == nullptr; }
      bool operator!=( std::nullptr_t ) const { return m_ptr != nullptr; }

      // Optional: reset to new pointer
      void reset( Type* ptr = nullptr ) {
         cleanup( );
         m_ptr = ptr;
      }

      // Destructor: automatically free
      ~UnPtr( ) {
         cleanup( );
      }
   };

}  // namespace seneca

#endif // SENECA_UNPTR_H