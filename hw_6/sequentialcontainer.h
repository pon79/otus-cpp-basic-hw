#ifndef SEQUENTIALCONTAINER_H
#define SEQUENTIALCONTAINER_H

#include <cstddef>
#include <iostream>
#include <cuchar>   // size_t
#include <initializer_list>
#include <algorithm> // copy


template <typename T>
class SequentialContainer
{
public:
    // Конструктор по умолчанию
    SequentialContainer() : m_region{ nullptr }, m_size{0} {}

    // Конструктор с заданным размером
    SequentialContainer(size_t n) : m_region{ new T[n] }, m_size{n} {
        for( size_t index{0}; index < m_size ; index++) {
            m_region[index] = T{};
        }
    }

    // Конструктор с инициализацией списка
    SequentialContainer(std::initializer_list<T> list)
        : m_region{ new T[list.size()] }
        , m_size{list.size()}
    {
        std::copy(list.begin(), list.end(), m_region);
    }

    ~SequentialContainer() { delete[] m_region; }

    void push_back( const T& value )
    {
        T* new_region = new T[m_size + 1];

        for (size_t i = 0; i < m_size; ++i) {
            new_region[i] = m_region[i];
        }

        new_region[m_size] = value;
        delete [] m_region;
        m_region = new_region;
        m_size += 1;
    }

    void erase(size_t eraseIndex)
    {
        if( eraseIndex >= m_size ) {
            return;
        }

        T* new_region = new T[m_size - 1];

        for (size_t index = 0; index < eraseIndex; ++index) {
            new_region[index] = m_region[index];
        }

        for (size_t index = eraseIndex + 1; index < m_size; ++index) {
            new_region[index - 1] = m_region[index];
        }

        delete [] m_region;
        m_region = new_region;
        m_size -= 1;
    }
        
    void insert(size_t insertIndex , const T& value)
    {
        if( insertIndex > m_size ) {
            return;
        }

        T* new_region = new T[m_size + 1];

        for (size_t index = 0; index < insertIndex; ++index) {
            new_region[index] = m_region[index];
        }

        new_region[insertIndex] = value;

        for (size_t index = insertIndex; index < m_size; ++index) {
            new_region[index + 1] = m_region[index];
        }

        delete [] m_region;
        m_region = new_region;
        m_size += 1;
    }

    size_t size() const { return m_size; }

    T& operator[](size_t index)
    {
        return m_region[index]; // TO DO check index
    }

    const T& operator[](size_t index) const
    {
        return m_region[index]; // TO DO check index
    }

private:
    T *m_region;
    size_t m_size;
};

template <typename T>
inline std::ostream& operator<<( std::ostream& stream, SequentialContainer<T> &container)
{
    for( std::size_t index{0}; index < container.size() ; index++ ) {
        std::cout << container[index];
        std::cout << (index < container.size() - 1 ? ", " : "\n");
    }
    return stream;
}

#endif // SEQUENTIALCONTAINER_H
