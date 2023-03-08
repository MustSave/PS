N = int(input())
dp = [int(input()) for _ in range(N)]
test = [0 for _ in range(N)]
test[0] = dp[0]
if N > 1: test[1] = dp[0] + dp[1]
if N > 2: test[2] = max(dp[0], dp[1]) + dp[2]

for i in range(3, N):
    test[i] = max(test[i-3]+dp[i-1]+dp[i], test[i-2]+dp[i])
print(test[N-1])

# 2
# 1 2, 2 1
# 1 2 1, 2 2
# 1 2 2, 2 1 2