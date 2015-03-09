#include <iostream.h>
#include <vector.h>

using namespace std;

class SmallProblem
{

public:
    SmallProblem(int capacity, int items);
    ~SmallProblem();
    void setValue(int* value);
    void setWeight(int* weight);
    void printTable();

private:
    int m_capacity; // the knapsack capacity
    int m_items;    // number of items
    int O(int k, int j);
    int* m_value;
    int* m_weight;
    vector<vector<int> > table;
    void makeTable();
    void getSolution();
};

// implementation of constructor
SmallProblem::SmallProblem(int capacity, int items)
{
    m_capacity = capacity;
    m_items    = items;
}

SmallProblem::~SmallProblem()
{
}

void SmallProblem::setValue(int* value)
{
    m_value = value;
}

void SmallProblem::setWeight(int* weight)
{
    m_weight = weight;
}

void SmallProblem::makeTable()
{
    //http://stackoverflow.com/questions/21663256/how-to-initialize-a-vector-of-vectors
    table = vector<vector<int> >(m_capacity+1, vector<int>(m_items+1));

    for(int k=0; k<m_capacity+1; k++)
    {
        for(int j=0; j<m_items+1; j++)
        {
            table[k][j] = O(k, j);
        }
    }
}

void SmallProblem::printTable()
{
    printf("  sizeof m_value  is %d\n", sizeof(m_value));
    printf("  sizeof m_weight is %d\n", sizeof(m_weight));
    printf("  Knapsack capacity is %d\n", m_capacity);

    //
    makeTable();

    // printing the value list
    printf("\n  m_value  = { ");
    for(int i=1; i<sizeof(m_value)+1; i++)
        printf("%d, ", m_value[i]);
    printf("}\n");

    // printing the weight list
    printf("\n  m_weight = { ");
    for(int i=1; i<sizeof(m_weight)+1; i++)
        printf("%d, ", m_weight[i]);
    printf("}\n");

    // printing table
    printf("\n");
    for(int k=0; k<m_capacity+1; k++)
    {
        for(int j=0; j<m_items+1; j++)
        {
            printf("\t%d ", table[k][j]);
        }
        printf("\n");
    }

    //
    getSolution();
}

void SmallProblem::getSolution()
{
    int j = m_items;
    int k = m_capacity;

    //printf("j=%d, k=%d\n", j, k);

    vector<int> solution = vector<int>(m_items+1);

    while(j > 0)
    {
        bool incluiu = table[k][j] != table[k][j-1];
        solution[j] = incluiu ? 1 : 0;

        if(incluiu)
        {
            k -= m_weight[j];
        }
        j--;
    }

    // printing the solution
    printf("\n  solution = { ");
    for(int i=1; i<m_items+1; i++)
        printf("%d, ", solution[i]);
    printf("}\n");
}

int SmallProblem::O(int k, int j)
{
    if(j==0)
        return 0;
    else if (m_weight[j] <= k)
    {
        //return max( O(k, j-1), m_value[j] + O(k-m_weight[j], j-1) );
        return max( table[k][j-1], m_value[j] + table[k-m_weight[j]][j-1] );
    }
    else
    {
        //return table[k][j-1];
        return O(k, j-1);
    }
}
