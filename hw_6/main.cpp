#include <iostream>

#include "sequentialcontainer.h"
#include <vector>

using namespace std;

int main()
{
    SequentialContainer myVector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for( std::size_t index{0}; index < myVector.size() ; index++ ) {
        cout << myVector[index];
        cout << (index < myVector.size() - 1 ? ", " : "\n");
    }

    cout << myVector.size() << '\n';

    myVector.erase(2); // третий элемент по счёту
    myVector.erase(3); // пятый элемент по счёту в первоначальном контейнере
    myVector.erase(4); // седьмой элемент по счёту в первоначальном контейнере

    for( std::size_t index{0}; index < myVector.size() ; index++ ) {
        cout << myVector[index];
        cout << (index < myVector.size() - 1 ? ", " : "\n");
    }

    return 0;
}
