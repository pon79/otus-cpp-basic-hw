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

    void puch_back( const int value );

    std::size_t size() const;

    int& operator[](const int index);
    int operator[](const int index) const;
};

#endif // MYLIST_H
