#include <string>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> Ns = vector<set<int>>(8);

int get_N(int N, int length)
{
    int ret = 0;

    for (int i = 0; i < length; i++)
        ret = ret * 10 + N;

    return ret;
}

void InsertIntoSet(int a, int b)
{
    int targetIndex = a + b+1;
    int tmp = 0;
    set<int>::iterator iterA, iterB;

    for (iterA = Ns[a].begin(); iterA != Ns[a].end(); iterA++)
    {
        for (iterB = Ns[b].begin(); iterB != Ns[b].end(); iterB++)
        {
            tmp = *iterA + *iterB;
            if (0 < tmp && tmp <= 32000) Ns[targetIndex].insert(tmp);
            tmp = *iterA - *iterB;
            if (0 < tmp && tmp <= 32000) Ns[targetIndex].insert(tmp);
            tmp = *iterA * *iterB;
            if (0 < tmp && tmp <= 32000) Ns[targetIndex].insert(tmp);
            
            if (*iterB != 0)
            {
                tmp = *iterA / *iterB;
                if (0 < tmp && tmp <= 32000) Ns[targetIndex].insert(tmp);
            }
        }
    }
}

int solution(int N, int number) {
    for (int i = 0; i < 8; i++)
    {
        Ns[i].insert(get_N(N, i+1));

        for (int j = 0; j < i; j++)
            InsertIntoSet(j, i - j -1);
        
        if (Ns[i].find(number) != Ns[i].end())
            return i+1;
    }

    return -1;
}