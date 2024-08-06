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
    m_size += 1; // обновляем размер
}

std::size_t MyList::size() const
{
    return m_size;
}
