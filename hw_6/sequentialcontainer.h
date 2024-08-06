#ifndef SEQUENTIALCONTAINER_H
#define SEQUENTIALCONTAINER_H

#include <cuchar> // size_t
#include <initializer_list>


class SequentialContainer
{
public:
    SequentialContainer();
    SequentialContainer( size_t n );
    SequentialContainer( std::initializer_list<int> list);

    ~SequentialContainer();

    void push_back( int value );
    void erase(const int eraseIndex );
    size_t size() const;

    int& operator[](int index);
    int operator[](int index) const;

private:
    int *m_region;
    size_t m_size;
};

#endif // SEQUENTIALCONTAINER_H
