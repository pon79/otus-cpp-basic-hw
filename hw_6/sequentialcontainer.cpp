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
