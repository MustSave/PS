# Longest Decreasing Subsequence(LDS)를 이용한 풀이

N = int(input())
power = list(map(int, input().split()))
dp = [1]*N
res = 0

for i in range(N):
    for j in range(i):
        if power[j] > power[i]:
            dp[i] = max(dp[i], dp[j]+1)

print(N-dp[N-1])