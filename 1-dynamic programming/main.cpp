#include <iostream>
#include "SmallTest.cpp"
#include "KSReader.cpp"

using namespace std;

int main()
{
    //printf("Testing SmallProblem.cpp class..\n");
    //SmallTest test = SmallTest();

    printf("Reading a Knapsack problem...\n");

    KSReader reader = KSReader("ks_4_0.txt");

    return 0;
}
