#include "StandartDeviation.hpp"

#include <cmath>

StandartDeviation::StandartDeviation()
    : m_n{0}
{}

void StandartDeviation::update(double next) {
    ++m_n;
    m_mean.update(next);
    m_vals.push_back(next);
}

double StandartDeviation::eval() const {
    if (m_n == 0) {
        return 0;
    }

    double mean{m_mean.eval()};
    double sum{0};
    for (double val : m_vals) {
        sum += pow((val -mean ), 2);
    }

    return sqrt (sum / m_n);
}

const char* StandartDeviation::name() const {
	return "std";
}
