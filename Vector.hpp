#pragma once

#include "IContainer.hpp"

namespace containers {

template<typename T>
class Vector : public IContainer<T> {
public:

    Vector()
        : IContainer<T>()
        , m_size{0}
        , m_data{nullptr}
    {}

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

    bool insert(size_t pos, T value) {
        if (pos > m_size) {
            return false;
        }

        T* new_data = new T[m_size + 1];

        for (size_t i = 0; i < pos; ++i) {
            new_data[i] = m_data[i];
        }

        new_data[pos] = value;

        for (size_t i = pos+1; i < m_size -1; ++i) {
            new_data[i] = m_data[i-1];
        }

        delete [] m_data;
        m_data = new_data;
        ++m_size;

        return true;
    }

    bool erase(size_t pos) {
        if (pos > m_size) {
            return false;
        }

        T* new_data = new T[m_size - 1];

        for (size_t i = 0; i < pos-1; ++i) {
            new_data[i] = m_data[i];
        }

        for (size_t i = pos; i < m_size; ++i) {
            new_data[i-1] = m_data[i];
        }

        delete [] m_data;
        m_data = new_data;
        --m_size;

        return true;
    }

    size_t size() const {
        return m_size;
    }

    T& operator[](size_t pos) const {
        return m_data[pos]; 
    }

private:
    size_t m_size;
    T* m_data;
};

} // containers