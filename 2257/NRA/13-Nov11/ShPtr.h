#ifndef SENECA_SHPTR_H
#define SENECA_SHPTR_H
#include <cstddef>  // for size_t, nullptr_t

namespace seneca {
   template <typename Type>
   class ShPtr {
      Type* m_ptr{};     // the actual object we own
      size_t* m_ptrCnt{};  // pointer to the shared counter

      // Clean up: decrease count, delete only if we're the last owner
      void wipeout() {
         if (m_ptrCnt && --(*m_ptrCnt) == 0) {  // if last owner...
            delete m_ptr;     // free the object
            delete m_ptrCnt;  // free the counter
         }
         m_ptr = nullptr;     // this ShPtr no longer owns anything
         m_ptrCnt = nullptr;
      }
   public:
      // Construct from raw pointer
      explicit ShPtr(Type* ptr = nullptr)
         : m_ptr(ptr)
         , m_ptrCnt(ptr ? new size_t(1) : nullptr)  // only make counter if not null
      {
      }
      // Copy: share ownership
      ShPtr(const ShPtr& sp)
         : m_ptr(sp.m_ptr), m_ptrCnt(sp.m_ptrCnt) {
         if (m_ptrCnt) ++(*m_ptrCnt);  // one more owner
      }
      // Copy assignment
      ShPtr& operator=(const ShPtr& obj) {
         if (this != &obj) {
            wipeout();                    // release old object
            m_ptr = obj.m_ptr;
            m_ptrCnt = obj.m_ptrCnt;
            if (m_ptrCnt) ++(*m_ptrCnt);    // join new group
         }
         return *this;
      }
      // Move: steal ownership (no count change)
      ShPtr(ShPtr&& dyingObj) noexcept
         : m_ptr(dyingObj.m_ptr), m_ptrCnt(dyingObj.m_ptrCnt) {
         dyingObj.m_ptr = nullptr;     // dying object gives up ownership
         dyingObj.m_ptrCnt = nullptr;
      }
      // Move assignment
      ShPtr& operator=(ShPtr&& dyingObj) noexcept {
         if (this != &dyingObj) {
            wipeout();
            m_ptr = dyingObj.m_ptr;
            m_ptrCnt = dyingObj.m_ptrCnt;
            dyingObj.m_ptr = nullptr;
            dyingObj.m_ptrCnt = nullptr;
         }
         return *this;
      }
      // How many owners?
      size_t count() const {
         return m_ptrCnt ? *m_ptrCnt : 0;
      }
      // Access raw pointer (non-const and const)
      Type* get() { return m_ptr; }
      const Type* get() const { return m_ptr; }

      // Arrow and deref (like real shared_ptr)
      Type* operator->() { return m_ptr; }
      const Type* operator->() const { return m_ptr; }

      Type& operator*() { return *m_ptr; }
      const Type& operator*() const { return *m_ptr; }

      // Compare with nullptr
      bool operator==(std::nullptr_t) const { return m_ptr == nullptr; }
      bool operator!=(std::nullptr_t) const { return m_ptr != nullptr; }

      // Destructor: automatically clean up
      ~ShPtr() {
         wipeout();
      }

   };
}

#endif