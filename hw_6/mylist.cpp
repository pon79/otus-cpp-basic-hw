#include "mylist.h"

MyList::MyList()
    : m_first{ nullptr }
    , m_last{ nullptr }
    , m_size{0}
{

}

MyList::MyList(std::initializer_list<int> list)
    : m_size{0}
{
    for( const auto &number : list ) {
        puch_back( number );
    }
}

MyList::~MyList()
{
    Node *node{ m_first };

    while ( node ) {
      Node *next = node->next;
      delete node;
      node = next;
    }
}

void MyList::puch_back(const int value)
{
    Node* new_node = new Node{}; // создание нового узла
    new_node->prev = m_last; // предыдущим элементом станет последний
    new_node->next = nullptr; // следующего элемента пока нет
    new_node->data = value; // сохраняем пользовательские данные

    m_last = new_node; // обновляем указатель на последний    

    if( m_size > 0 )
        m_last->prev->next = m_last;

    if( m_size == 0 )
        m_first = new_node;

    m_size += 1; // обновляем размер
}

void MyList::erase(const int eraseIndex)
{
    if( eraseIndex < 0 && eraseIndex >= m_size )
        return;

    Node *node = nullptr;

    if( eraseIndex == 0 ) {
        node = m_first;
        m_first = m_first->next;
        m_first->prev = nullptr;
    } else if( eraseIndex == (m_size - 1) ) {
        node = m_last;
        m_last = m_last->prev;
        m_last->next = nullptr;
    } else {
        node = m_first;

        for( size_t index{0}; index < eraseIndex ; index++) {
            node = node->next;
        }

        node->prev->next = node->next;
    }

    m_size--;
    delete node;
}

void MyList::insert(const int insertIndex, const int value)
{
    Node *node = new Node{};
    node->data = value;

    if( insertIndex == 0 ) {
        node->next = m_first;
        m_first = node;
        m_first->next->prev = m_first;
    } else if( insertIndex == (m_size - 1) ) {
        node->prev = m_last;
        m_last = node;
        m_last->prev->next = m_last;
    } else {
        Node *prevNode{ m_first };

        for( size_t index{0}; index < (insertIndex - 1) ; index++) {
            prevNode = prevNode->next;
        }

        node->next = prevNode->next;
        node->prev = prevNode;
        prevNode->next = node;
        node->next->prev = node;
    }

    m_size++;
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
