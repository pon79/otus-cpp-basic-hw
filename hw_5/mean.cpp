#include "mean.h"

Mean::Mean() : m_sum{0}, m_count{0}
{
}

inline void Mean::update(double next)
{
    m_sum += next;
    m_count++;
}

double Mean::eval() const {
    return m_sum / m_count;
}

const char *Mean::name() const {
    return "mean";
}
