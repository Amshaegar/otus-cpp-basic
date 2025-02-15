#include "Max.hpp"

Max::Max()
    : m_max{0}
	, m_firstValue(true)
{}

void Max::update(double next) {
	if (m_firstValue) {
		m_max = next;
		m_firstValue = false;
	}

	if (next > m_max) {
		m_max = next;
	}
}

double Max::eval() const {
	return m_max;
}

const char* Max::name() const {
	return "max";
}
