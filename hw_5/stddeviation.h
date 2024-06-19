#ifndef STDDEVIATION_H
#define STDDEVIATION_H

#include <vector>

#include "mean.h"

class StdDeviation : public IStatistics
{
public:
    StdDeviation();

    void update(double next) override;
    double eval() const override;
    const char * name() const override;

private:
    Mean m_mean;
    std::vector<double> m_values;
};

#endif // STDDEVIATION_H
