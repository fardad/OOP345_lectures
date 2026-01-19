#ifndef SENECA_INTARRAY
#define SENECA_INTARRAY
namespace seneca {
   class IntArray {
      int* m_data;
      int m_size;
      void resize(int newsize);
   public:
      IntArray(int size=1);
      IntArray(const IntArray& cp);
      IntArray& operator=(const IntArray& cp);
      int size()const;
      int& operator[](int index);
      const int& operator[](int index)const;
      virtual ~IntArray();
      std::ostream& display(std::ostream& ostr = std::cout)const;

   };
   std::ostream& operator<<(std::ostream& ostr, const IntArray& Ro);

}

#endif // !SENECA_INTARRAY