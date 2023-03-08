#include <stdio.h>
#include <math.h>
#define max(x, y) x>y?x:y

int main() {
    int N;
    int dp[100000];
    int m = -10000;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %d", &dp[i]);
        dp[i] = i == 0 ? dp[i] : max(dp[i-1] + dp[i], dp[i]);
        m = max(dp[i], m);
    }

    printf("%d", m);
}