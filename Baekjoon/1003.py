T = int(input())

N = []
for _ in range(T):
    N.append(int(input()))

dp = [[0]*2 for _ in range(40)]
dp[0] = [1, 0]
dp[1] = [0, 1]

for i in range(2, max(N)+1):
    dp[i][0] = dp[i-2][0] + dp[i-1][0]
    dp[i][1] = dp[i-2][1] + dp[i-1][1]

for i in N:
    print(dp[i][0], dp[i][1])