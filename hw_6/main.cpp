#include <iostream>

#include "sequentialcontainer.h"

using namespace std;

int main()
{
    SequentialContainer myVector;

    myVector.push_back( 1 );
    myVector.push_back( 2 );

    cout << myVector[2] << '\n';

    return 0;
}
