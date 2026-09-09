#pragma once
#ifndef SENECA_MYARRAY_H
#define SENECA_MYARRAY_H
namespace seneca {
    template <typename T>
    class MyArray {
        T a[50]{};
        T dummy{};
    public:
        MyArray() = default;
        T& operator[](unsigned i) {
            return i < 50 ? a[i] : dummy;
        }
    };
}
#endif // !SENECA_ARRAY_H


