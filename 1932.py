N = int(input())
dp = [list(map(int, input().split())) for _ in range(N)]

for i in range(1, N):
    for j in range(len(dp[i])):
        dp[i][j] = max(dp[i-1][j-1] if j != 0 else 0, dp[i-1][j] if j != i else 0) + dp[i][j]

print(max(dp[N-1]))