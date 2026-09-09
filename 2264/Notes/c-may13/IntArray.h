#ifndef SENECA_INTARRAY_H
#define SENECA_INTARRAY_H
namespace seneca {
	class IntArray {
		size_t m_size{};
		int* m_data{};
	public:
		IntArray(size_t size);
		IntArray(const IntArray& other);
		IntArray& operator=(const IntArray& other);
		IntArray(IntArray&& other)noexcept;
		IntArray& operator=(IntArray&& other)noexcept;
		virtual ~IntArray();
		int& operator[](size_t index);
		const int& operator[](size_t index)const;
		size_t size()const;

	};
}
#endif

