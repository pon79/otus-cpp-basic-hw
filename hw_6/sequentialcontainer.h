#ifndef SEQUENTIALCONTAINER_H
#define SEQUENTIALCONTAINER_H

#include <cuchar>

class SequentialContainer
{
public:
    SequentialContainer();


private:
    int *m_region;
    size_t m_size;
};

#endif // SEQUENTIALCONTAINER_H
