#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <cuchar>   // size_t



template <typename T>
class MyList
{
    struct Node {
        Node* next{}; // указатель на следующий элемент Node
        Node* prev{}; // указатель на предыдущий элемент Node
        T data; // пользовательские данные (хранимый объект)
    };

    Node* m_first{nullptr};
    Node* m_last{nullptr};
    std::size_t m_size{0};

public:
    // Конструктор по умолчанию
    MyList() = default;

    // Конструктор с инициализацией списка
    MyList( std::initializer_list<T> list)
    {
        for( const auto &number : list ) {
            push_back( number );
        }
    }

    ~MyList()
    {
        Node *current{ m_first };

        while ( current ) {
          Node *next = current->next;
          delete current;
          current = next;
        }
    }

    void push_back(const T& value)
    {
        Node* new_node = new Node{nullptr, m_last, value};

        m_last = new_node; // обновляем указатель на последний

        if( m_size > 0 )
            m_last->prev->next = m_last;

        if( m_size == 0 )
            m_first = new_node;

        m_size += 1; // обновляем размер
    }

    void erase(size_t eraseIndex )
    {
        if (eraseIndex >= m_size) return;

        Node* node = m_first;

        if (m_size == 1) { 
            // Если удаляем единственный элемент
            m_first = nullptr;
            m_last = nullptr;
        } else if (eraseIndex == 0) { 
            // Удаляем первый элемент
            m_first = m_first->next;
            m_first->prev = nullptr;
        } else if (eraseIndex == m_size - 1) { 
            // Удаляем последний элемент
            node = m_last;
            m_last = m_last->prev;
            m_last->next = nullptr;
        } else { 
            // Удаляем из середины
            for (std::size_t index = 0; index < eraseIndex; ++index) {
                node = node->next;
            }
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        delete node;
        m_size--;
    }

    void insert(size_t insertIndex , const T& value)
    {
        if (insertIndex > m_size) return;

        // Если вставляем в самый конец, просто используем push_back
        if (insertIndex == m_size) {
            push_back(value);
            return;
        }

        Node* new_node = new Node{};
        new_node->data = value;

        if (insertIndex == 0) {
            // Вставка в начало
            new_node->next = m_first;
            new_node->prev = nullptr;
            if (m_first) m_first->prev = new_node;
            m_first = new_node;
            if (m_size == 0) m_last = new_node;
        } else {
            // Вставка в середину
            Node* prevNode = m_first;
            for (std::size_t index = 0; index < insertIndex - 1; ++index) {
                prevNode = prevNode->next;
            }

            new_node->next = prevNode->next;
            new_node->prev = prevNode;

            // ИСПРАВЛЕНО: корректно связываем соседние узлы с новым
            prevNode->next->prev = new_node; 
            prevNode->next = new_node;
        }
        m_size++;
    }

    std::size_t size() const { return m_size; }

    T& operator[](size_t index)
    {
        // TODO: добавить проверку на выход за границы
        Node* node = m_first;
        for (std::size_t i = 0; i < index; ++i) {
            node = node->next;
        }
        return node->data;
    }

    const T& operator[](std::size_t index) const {
        // TODO: добавить проверку на выход за границы
        Node* node = m_first;
        for (std::size_t i = 0; i < index; ++i) {
            node = node->next;
        }
        return node->data;
    }
};

template <typename T>
inline std::ostream& operator<<( std::ostream& stream, MyList<T> &list)
{
    for( std::size_t index{0}; index < list.size() ; index++ ) {
        std::cout << list[index];
        std::cout << (index < list.size() - 1 ? ", " : "\n");
    }
    return stream;
}

#endif // MYLIST_H
