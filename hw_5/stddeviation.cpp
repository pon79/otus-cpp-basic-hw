#include "stddeviation.h"
#include <iostream>

#include <cmath>

StdDeviation::StdDeviation()
{
}

inline void StdDeviation::update(double next)
{
    m_mean.update( next );
    m_values.push_back( next );
}

double StdDeviation::eval() const {

    if( m_values.size() < 1 ) {
        std::cerr << "few values \n";
        return 0;
    }

    double powSum{};

    for( const auto & value : m_values ) {
        powSum += std::pow( value - m_mean.eval(), 2 );
    }

    return std::sqrt( powSum / m_values.size() );
}

const char *StdDeviation::name() const {
    return "std";
}
