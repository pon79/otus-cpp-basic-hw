#ifndef MYLIST_H
#define MYLIST_H

struct Node {
    Node* next; // указатель на следующий элемент Node
    Node* prev; // указатель на предыдущий элемент Node
    int data; // пользовательские данные (хранимый объект)
};

class MyList
{
    Node *m_first;
    Node *m_last;
public:
    MyList();
};

#endif // MYLIST_H
