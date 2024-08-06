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

void SequentialContainer::erase(const int eraseIndex)
{
    if( eraseIndex < 0 || eraseIndex >= m_size ) {
        return;
    }

    int* new_region = new int[m_size - 1];

    for (size_t index = 0; index < eraseIndex; ++index) {
        new_region[index] = m_region[index];
    }

    for (size_t index = eraseIndex + 1; index < m_size; ++index) {
        new_region[index - 1] = m_region[index];
    }

    delete [] m_region;
    m_region = new_region;
    m_size--;
}

void SequentialContainer::insert(const int insertIndex, const int value)
{
    if( insertIndex < 0 || insertIndex >= m_size ) {
        return;
    }

    int* new_region = new int[m_size + 1];

    for (size_t index = 0; index < insertIndex; ++index) {
        new_region[index] = m_region[index];
    }

    new_region[insertIndex] = value;

    for (size_t index = insertIndex + 1; index <= m_size; ++index) {
        new_region[index] = m_region[index - 1];
    }

    delete [] m_region;
    m_region = new_region;
    m_size++;
}

size_t SequentialContainer::size() const
{
    return m_size;
}

int& SequentialContainer::operator[](const int index)
{
    // TO DO check index >= 0 && index < m_size
    return m_region[index];
}

int SequentialContainer::operator[](const int index) const
{
    // TO DO check index >= 0 && index < m_size
    return m_region[index];
}
