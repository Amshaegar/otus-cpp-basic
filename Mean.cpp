#include "Mean.hpp"

Mean::Mean()
    : m_sum{0}
    , m_n{0}
{}

void Mean::update(double next) {
    ++m_n;
    m_sum += next;
}

double Mean::eval() const {
    if (m_n == 0) {
        return 0;
    }

    return m_sum / m_n;
}

const char* Mean::name() const {
	return "mean";
}
