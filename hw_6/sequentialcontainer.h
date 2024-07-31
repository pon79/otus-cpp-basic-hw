#ifndef SEQUENTIALCONTAINER_H
#define SEQUENTIALCONTAINER_H

#include <cuchar>

class SequentialContainer
{
public:
    SequentialContainer();    
    ~SequentialContainer();

    void push_back( int value );
    size_t size() const;

    int& operator[](int index);

private:
    int *m_region;
    size_t m_size;
};

#endif // SEQUENTIALCONTAINER_H
