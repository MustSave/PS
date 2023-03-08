N = int(input())
cost = [int(input()) for _ in range(N)]
dp = [0]*N
dp[0] = cost[0]
if N > 1:dp[1] = cost[0] + cost[1]
if N > 2:dp[2] = max(cost[0]+ cost[2], cost[1] + cost[2], dp[1]) 
for i in range(3, N):
    dp[i] = max(dp[i-2] + cost[i], dp[i-3] + cost[i-1] + cost[i], dp[i-1])

print(dp[N-1])