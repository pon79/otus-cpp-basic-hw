#include <iostream>

#include "sequentialcontainer.h"
#include <vector>

using namespace std;

int main()
{
    SequentialContainer myVector;

    myVector.push_back( 1 );
    myVector.push_back( 2 );

    cout << myVector[1] << '\n';

    cout << myVector.size() << '\n';

    return 0;
}
