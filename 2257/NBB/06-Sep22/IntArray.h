#ifndef SENECA_INTARRAY
#define SENECA_INTARRAY
namespace seneca {
   class IntArray {
      int* m_data;
      size_t m_size;
      void resize(size_t newsize);
   public:
      IntArray(size_t size=1);
      IntArray(const IntArray& cp);
      IntArray(IntArray&& mv)noexcept;
      IntArray& operator=(const IntArray& cp);
      IntArray& operator=(IntArray&& mv)noexcept;

      size_t size()const;
      int& operator[](size_t index);
      const int& operator[](size_t index)const;
      virtual ~IntArray();
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const IntArray& Ro);

}

#endif // !SENECA_INTARRAY