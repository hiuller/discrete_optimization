#include <iostream>
#include "SmallProblem.cpp"

using namespace std;

int main()
{
    printf("Testing SmallProblem.cpp class..\n");

    int capacity = 7;
    int items = 4;
    int values[]  = {0, 16, 19, 23, 28};
    int weights[] = {0,  2,  3,  4,  5};

    SmallProblem sp = SmallProblem(capacity, items);
    sp.setValue (&values[0]);
    sp.setWeight(&weights[0]);

    sp.printTable();
    return 0;
}
