#include <iostream>

#include "sequentialcontainer.h"
#include <vector>

int main()
{
    SequentialContainer myVector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::cout << myVector;

    std::cout << myVector.size() << '\n';

    myVector.erase(2); // третий элемент по счёту
    myVector.erase(3); // пятый элемент по счёту в первоначальном контейнере
    myVector.erase(4); // седьмой элемент по счёту в первоначальном контейнере

    std::cout << myVector;

    return 0;
}
