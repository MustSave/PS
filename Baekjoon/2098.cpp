#include <iostream>

using namespace std;

#define MAX 987654321

int N;
int matrix[16][16];
int dp[16][1<<16];
int visitedAll;

int dfs(int start, int visited) {
    if (visited == visitedAll) {
        dp[start][visited] = matrix[start][0] == 0 ? MAX : matrix[start][0];
        return dp[start][visited];
    }

    if (dp[start][visited] != -1)
        return dp[start][visited];

    dp[start][visited] = MAX;
    for (int i = 1; i < N; i++) {
        int bitSelector = 1 << i;
        if ((visited & bitSelector) == bitSelector || matrix[start][i] == 0) continue;

        dp[start][visited] = min(dp[start][visited], matrix[start][i] + dfs(i, visited | bitSelector));
    }

    return dp[start][visited];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    visitedAll = (1 << N) - 1;

    fill(&dp[0][0], &dp[N-1][1<<16], -1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << dfs(0, 1);
}