#pragma once

#include "IStatistics.hpp"

#include "Mean.hpp"

#include <vector>

class Mean;

class StandartDeviation : public IStatistics {
public:
    StandartDeviation();

	void update(double next) override;
	double eval() const override;
	const char* name() const override;

private:
    Mean m_mean;
    std::vector<double> m_vals;
    int m_n;
};
