import sys;input=sys.stdin.readline;

N, K = map(int, input().split())
coin = [int(input()) for _ in range(N)]

dp = [0] * (K+1)

for c in coin:
    if c > K: continue
    dp[c] += 1
    for k in range(c+1, K+1):
        dp[k] += dp[k-c]

print(dp[-1])