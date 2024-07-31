#include "sequentialcontainer.h"

#include <algorithm>

SequentialContainer::SequentialContainer()
    : m_region{ nullptr }
    , m_size{0}
{
}

SequentialContainer::SequentialContainer(size_t n)
    : m_region{ new int[n] }
    , m_size{n}
{
    for( size_t index{0}; index < m_size ; index++) {
        m_region[index] = 0;
    }
}

SequentialContainer::SequentialContainer(std::initializer_list<int> list)
    : m_region{ new int[list.size()] }
    , m_size{list.size()}
{
    std::copy(list.begin(), list.end(), m_region);
}

SequentialContainer::~SequentialContainer()
{
    delete[] m_region;
}

void SequentialContainer::push_back(int value)
{
    int* new_region = new int[m_size + 1];

    for (size_t i = 0; i < m_size; ++i) {
        new_region[i] = m_region[i];
    }

    new_region[m_size] = value;
    delete [] m_region;
    m_region = new_region;
    m_size += 1;
}

size_t SequentialContainer::size() const
{
    return m_size;
}

int& SequentialContainer::operator[](int index)
{
    if( index >= 0 && index < m_size ) {
        return m_region[index];
    } else {
        // TO DO  exception handling
    }
}

int SequentialContainer::operator[](int index) const
{
    if( index >= 0 && index < m_size ) {
        return m_region[index];
    } else {
        // TO DO  exception handling
    }
}
