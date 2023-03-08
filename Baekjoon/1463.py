N = int(input())
dp = [0, 0, 1, 1, 2, 3, 2, 3, 3, 2, 3]
dp+=[0 for _ in range(N-10)]
for i in range(11, N+1):
    dp[i] = dp[i-1]
    if i%3==0: dp[i] = min(dp[i//3], dp[i])
    if i%2==0: dp[i] = min(dp[i//2], dp[i])
    dp[i] += 1
print(dp[N])