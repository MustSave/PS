#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, M, x;
vector<pair<int,int>> graph[2][1001];
int ans[1001] = {0, };
const int INF = 1e9 + 7;
vector<int> dist[2];

int main() {
    scanf("%d %d %d", &n, &M, &x);

    for (int i = 0; i < M; i++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        graph[0][a].push_back({t, b});
        graph[1][b].push_back({t, a});
    }


    dist[0].resize(n + 1, INF);
	dist[1].resize(n + 1, INF);

    priority_queue<pair<int, int>> pq;
    for (int k = 0; k < 2; k++) {
        dist[k][x] = 0;
        pq.push({0, x});

        while (!pq.empty()) {
            // const auto& [d, now] = pq.top();
            const auto [d, now] = pq.top();
            // int d = pq.top().first;
            // int now = pq.top().second;
            printf("## d: %d, now: %d ##\n", d, now);
            pq.pop();

            for (const auto& [cost, next]: graph[k][now]) {
                int next_d = d + cost;
                printf("## cost: %d, next_d: %d, next: %d ##\n", cost, next_d, next);
                if (next_d < dist[k][next]) {
                    dist[k][next] = next_d;
                    pq.push({next_d, next});
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, dist[0][i] + dist[1][i]);
    }

    printf("%d", answer);
}


/**
## d: 0, now: 2 ##
## next_d: 1, next: 1 ##
## next_d: 6, next: 3 ##
## d: 6, now: 3 ##
## next_d: 5, next: 2 ##
## next_d: 3, next: 3 ##
## next_d: 10, next: 4 ##
## d: 10, now: 4 ##
## next_d: 5, next: 1 ##
## next_d: 7, next: 4 ##
## d: 7, now: 4 ##
## next_d: 5, next: 1 ##
## next_d: 7, next: 4 ##
## d: 3, now: 3 ##
## next_d: 5, next: 2 ##
## next_d: 3, next: 3 ##
## next_d: 8, next: 4 ##
## d: 1, now: 1 ##
## next_d: 5, next: 2 ##
## next_d: 3, next: 3 ##
## next_d: 8, next: 4 ##
## d: 0, now: 2 ##
## next_d: 4, next: 1 ##
## next_d: 7, next: 4 ##
## d: 7, now: 4 ##
## next_d: 5, next: 2 ##
## next_d: 6, next: 3 ##
## d: 6, now: 3 ##
## next_d: 5, next: 2 ##
## next_d: 6, next: 3 ##
## d: 4, now: 1 ##
## next_d: 5, next: 2 ##
## next_d: 6, next: 3 ##
*/