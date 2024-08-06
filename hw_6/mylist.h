#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <cstddef> // size_t

struct Node {
    Node* next{}; // указатель на следующий элемент Node
    Node* prev{}; // указатель на предыдущий элемент Node
    int data; // пользовательские данные (хранимый объект)
};

class MyList
{
    Node *m_first;
    Node *m_last;
    std::size_t m_size;
public:
    MyList();
    MyList( std::initializer_list<int> list);

    void puch_back( const int value );
    void erase(const int eraseIndex );
    void insert(const int insertIndex , const int value);

    std::size_t size() const;

    int& operator[](const int index);
    int operator[](const int index) const;
};

inline std::ostream& operator<<( std::ostream& stream, MyList &list)
{
    for( std::size_t index{0}; index < list.size() ; index++ ) {
        std::cout << list[index];
        std::cout << (index < list.size() - 1 ? ", " : "\n");
    }
    return stream;
}

#endif // MYLIST_H
