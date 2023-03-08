import sys;input=sys.stdin.readline;

N, M = map(int, input().split())
active = list(map(int, input().split()))
cost = list(map(int, input().split()))

dp = [[-1 for _ in range(max(cost)*N+1)] for _ in range(N)]
dp[0][cost[0]] = active[0]
ans = 1000000000
if active[0] >= M: ans = cost[0]

for i in range(1, N):
    for j in range(len(dp[i])-1, -1, -1):
        if dp[i-1][j] != -1:
            dp[i][j] = max(dp[i][j], dp[i-1][j])
            if j+cost[i] < len(dp[i]):
                dp[i][j+cost[i]] = max(dp[i][j+cost[i]], dp[i-1][j]+active[i])

                if dp[i][j+cost[i]] >= M: ans = min(ans, j+cost[i])
    dp[i][cost[i]] = max(dp[i][cost[i]], active[i])
    if dp[i][cost[i]] >= M: ans = min(ans, cost[i])

# print(*dp, sep='\n')
print(ans)