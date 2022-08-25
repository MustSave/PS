/* Input 빨리 받을 수 있도록 하기*/
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <iostream>

#define pii pair<int,int>
using namespace std;

vector<pair<int, int>> edges[20000];
int result[20000];
int visited[20000];

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.second > b.second;
    }
};

void Dijkstra(int V, int E, int K) {
    int inf = 10 * E + 1;
    priority_queue<pii, vector<pii>, cmp> pq;

    for (int i = 0; i < V; i++) {
        result[i] = i == K - 1 ? 0 : inf;
        visited[i] = false;
    }

    pq.push(make_pair(K-1, 0));

    while(!pq.empty()) {
        pair<int,int> tmp = pq.top(); pq.pop();
        int index = tmp.first;

        if (visited[index]) continue;
        
        visited[index] = true;
        for (auto i : edges[index]) {
            int dest = i.first;
            int newWeight = result[index] + i.second;
            if (result[dest] > newWeight) {
                result[dest] = newWeight;
                pq.push(make_pair(dest, newWeight));
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (result[i] != inf) 
            printf("%d\n", result[i]);
        else 
            printf("INF\n");
    }
}

int main() {
    
    int V, E, K;
    scanf("%d %d %d", &V, &E, &K);
    
    int u, v, w; // 0 <= w <= 10
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u-1].push_back(make_pair(v-1, w));
    }

    Dijkstra(V, E, K);
}