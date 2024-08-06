#ifndef SEQUENTIALCONTAINER_H
#define SEQUENTIALCONTAINER_H

#include <iostream>
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
    void insert(const int insertIndex , const int value);

    size_t size() const;

    int& operator[](const int index);
    int operator[](const int index) const;

private:
    int *m_region;
    size_t m_size;
};

inline std::ostream& operator<<( std::ostream& stream, SequentialContainer &container)
{
    for( std::size_t index{0}; index < container.size() ; index++ ) {
        std::cout << container[index];
        std::cout << (index < container.size() - 1 ? ", " : "\n");
    }
    return stream;
}

#endif // SEQUENTIALCONTAINER_H
