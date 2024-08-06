#include <iostream>

#include "sequentialcontainer.h"
#include "mylist.h"

void testSequentialContainer();

void testMyList();

int main()
{

    testSequentialContainer();

    std::cout << '\n';

    testMyList();

    return 0;
}

void testSequentialContainer()
{
    SequentialContainer myVector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::cout << myVector;

    std::cout << myVector.size() << '\n';

    myVector.erase(2); // третий элемент по счёту
    myVector.erase(3); // пятый элемент по счёту в первоначальном контейнере
    myVector.erase(4); // седьмой элемент по счёту в первоначальном контейнере

    std::cout << myVector;

    myVector.insert(0, 10);

    std::cout << myVector;

    myVector.insert( myVector.size() / 2 , 20);

    std::cout << myVector;

    myVector.push_back( 30 );

    std::cout << myVector;
}

void testMyList()
{
    MyList myList = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::cout << myList;

    std::cout << myList.size() << '\n';

    myList.erase(2); // третий элемент по счёту
    myList.erase(3); // пятый элемент по счёту в первоначальном контейнере
    myList.erase(4); // седьмой элемент по счёту в первоначальном контейнере
    std::cout << myList;

    myList.insert( 0, 10 );
    std::cout << myList;

    myList.insert( myList.size() / 2, 20 );
    std::cout << myList;

    myList.puch_back( 30 );
    std::cout << myList;
}
