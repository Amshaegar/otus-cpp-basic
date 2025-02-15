#include "Min.hpp"

Min::Min()
    : m_min{0}
    , m_firstValue(true)
{}

void Min::update(double next) {
    if (m_firstValue) {
        m_min = next;
        m_firstValue = false;
    }
    
    if (next < m_min) {
        m_min = next;
    }
}

double Min::eval() const {
    return m_min;
}

const char* Min::name() const {
    return "min";
}