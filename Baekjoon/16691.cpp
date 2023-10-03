#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX 987654321

int N;
int coord[16][2];
double matrix[16][16];
double dp[16][1<<16];
int visitedAll;

double calcDistance(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return 0;
    return sqrt(pow(x1-x2, 2) + pow(y1 - y2, 2));
}

double dfs(int start, int visited) {
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
    scanf("%d", &N);
    visitedAll = (1 << N) - 1;

    fill(&dp[0][0], &dp[N-1][1<<16], -1);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &coord[i][0], &coord[i][1]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = calcDistance(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
        }
    }

    printf("%f", dfs(0, 1));
}