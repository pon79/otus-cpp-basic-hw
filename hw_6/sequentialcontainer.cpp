#include "sequentialcontainer.h"

SequentialContainer::SequentialContainer()
    : m_region{ nullptr }
    , m_size{0}
{

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

int& SequentialContainer::operator[](int index)
{
    if( index > 0 && index < m_size ) {
        return m_region[index];
    } else {
        // TO DO  exception handling
    }
}
