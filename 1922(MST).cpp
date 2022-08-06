#include <stdio.h>
#include <queue>
#include <map>

using namespace std;

struct edge {
    int a, b, cost;

    bool operator < (const edge& b) const {
        return cost > b.cost;
    }
};

priority_queue<edge> edges;
int* root;

int GetRoot(int node)
{
    int tmp = node;

    while(root[node] != node)
        node = root[node];

    root[tmp] = node;
    return node;
}

int main()
{
    int N, M;
    int answer = 0;

    scanf("%d", &N);
    scanf("%d", &M);

    root = new int[M];
    
    for (int i = 0; i < M; i++)
    {
        edge* tmp = new edge;
        scanf("%d %d %d", &(tmp->a), &(tmp->b), &(tmp->cost));
        edges.push(*tmp);

        root[tmp->a] = tmp->a;
        root[tmp->b] = tmp->b;
    }

    edge tmp;

    while(edges.empty() == false)
    {
        tmp = edges.top();
        edges.pop();

        int rootA = GetRoot(tmp.a);
        int rootB = GetRoot(tmp.b);

        if (rootA != rootB)
        {
            root[rootB] = rootA;
            answer += tmp.cost;
        }
    }

    printf("%d", answer);
}