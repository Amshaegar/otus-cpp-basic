#pragma once

#include "IContainer.hpp"
#include <iostream>

namespace containers {

template<typename T>
class Vector : public IContainer<T> {
public:

    Vector() : IContainer<T>() {}

    ~Vector() {
        delete [] m_data;
    }

    void push_back(T value) {
        T* new_data = new T[m_size + 1];
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }
        new_data[m_size] = value;
        delete [] m_data;
        m_data = new_data;
        ++m_size;
    }

    void insert(size_t pos, T value) {
        checkRange(pos);

        T* new_data = new T[m_size + 1];

        for (size_t i = 0; i < pos; ++i) {
            new_data[i] = m_data[i];
        }

        new_data[pos] = value;

        for (size_t i = pos+1; i < m_size + 1; ++i) {
            new_data[i] = m_data[i-1];
        }

        delete [] m_data;
        m_data = new_data;
        ++m_size;
    }

    void erase(size_t pos) {
        checkRange(pos);

        T* new_data = new T[m_size - 1];

        for (size_t i = 0; i < pos; ++i) {
            new_data[i] = m_data[i];
        }

        for (size_t i = pos+1; i < m_size; ++i) {
            new_data[i-1] = m_data[i];
        }

        delete [] m_data;
        m_data = new_data;
        --m_size;
    }

    size_t size() const {
        return m_size;
    }

    const T& operator[](size_t pos) const {
        return m_data[pos]; 
    }

private:
    void checkRange(size_t pos) const {
        if (pos >= m_size) {
            throw std::out_of_range("Position out of container");
        }
    }

    size_t m_size{0};
    T* m_data{nullptr};
};

} // containers