#include "IntArray.h"
namespace seneca {
	IntArray::IntArray(size_t size){
		if (!size) size = 1;
		m_data = new int[m_size = size] {};
	}

	IntArray::IntArray(const IntArray& other){
		m_data = new int[m_size = other.m_size] {};
		for (size_t i = 0;i < m_size;m_data[i] = other[i], i++);
	}

	IntArray& IntArray::operator=(const IntArray& other){
		if (this != &other) {
			delete[] m_data;
			m_data = new int[m_size = other.m_size] {};
			for (size_t i = 0;i < m_size;m_data[i] = other[i], i++);
		}
		return *this;
	}

	IntArray::IntArray(IntArray&& other)noexcept {
		m_data = other.m_data;
		m_size = other.m_size;
		/* generally this will be the case where the other object completely emptied of 
		* all data, but in our case, an empty array has one element with size of 1
		other.m_data = nullptr;
		other.m_size = 0;
		*/
		other.m_data = new int[1] {};
		other.m_size = 1;
	}

	IntArray& IntArray::operator=(IntArray&& other)noexcept{
		if (this != &other) {
			delete[] m_data;
			m_data = other.m_data;
			m_size = other.m_size;
			/* See the comment in move constructor
			other.m_data = nullptr;
			other.m_size = 0;*/
			other.m_data = new int[1] {};
			other.m_size = 1;
		}
		return *this;
	}

	IntArray::~IntArray(){
		delete[] m_data;
	}

	int& IntArray::operator[](size_t index)	{
		if (index >= m_size) {
			int* newdata = new int[index + 1] {};
			for (size_t i = 0;i < m_size;i++) {
				newdata[i] = m_data[i];
			}
			delete[] m_data;
			m_data = newdata;
			m_size = index + 1;
		}
		return m_data[index];
	}
	// change the code of the following method to 
	// change the size of the array if the index is larger than
	// the size, without removing const from operator signature
	const int& IntArray::operator[](size_t index) const	{
		return m_data[index % m_size];
	}

	size_t IntArray::size() const{
		return m_size;
	}

}