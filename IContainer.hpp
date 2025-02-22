#pragma once

#include <cstddef>
#include <ostream>

namespace containers {

template<typename T>
class IContainer {
public:

    IContainer(){}
    virtual ~IContainer(){}

    virtual void push_back(T value) = 0;
    virtual bool insert(size_t pos, T value) = 0;
    virtual bool erase(size_t pos) = 0;
    virtual size_t size() const = 0;
    virtual T& operator[](size_t pos) const = 0;
};

} // containers

template<typename T>
std::ostream& operator<<(std::ostream& os, const containers::IContainer<T>& container)
{
    for (size_t i = 0; i < container.size();  ++i) {
        os << container[i];
        if(i != container.size()-1) {
            os << ", ";
        }
    }
    os << std::endl;
    return os;
}