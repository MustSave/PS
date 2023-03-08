import sys;input=sys.stdin.readline;print=sys.stdout.write;

[N, K] = list(map(int, input().split()))
coins = sorted([int(input()) for _ in range(N)], reverse=True)
ans = 0

for coin in coins:
    ans += K // coin
    K %= coin
    if K == 0: break

print(str(ans))