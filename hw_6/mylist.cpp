#include "mylist.h"

MyList::MyList()
    : m_first{ nullptr }
    , m_last{ nullptr }
    , m_size{0}
{

}

void MyList::puch_back(const int value)
{
    Node* new_node = new Node{}; // создание нового узла
    new_node->prev = m_last; // предыдущим элементом станет последний
    new_node->next = nullptr; // следующего элемента пока нет
    new_node->data = value; // сохраняем пользовательские данные

    m_last = new_node; // обновляем указатель на последний    

    if( m_last->prev )
        m_last->prev->next = new_node;

    if( m_size == 0 )
        m_first = new_node;

    m_size += 1; // обновляем размер
}

std::size_t MyList::size() const
{
    return m_size;
}

int& MyList::operator[](const int index)
{
    if( index == 0 )
        return m_first->data;

    Node *node{ m_first };

//     TO DO check index >= 0 && index < m_size

    for( size_t i{0}; i < index ; i++) {
        node = node->next;
    }

    return node->data;
}

int MyList::operator[](const int index) const
{
    if( index == 0 )
        return m_first->data;

    Node *node{ m_first };

//     TO DO check index >= 0 && index < m_size

    for( size_t i{0}; i < index ; i++) {
        node = node->next;
    }

    return node->data;
}
