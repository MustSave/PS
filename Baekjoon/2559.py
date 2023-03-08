import sys
input = sys.stdin.readline

[N, K] = list(map(int, input().split()))
temp = [0]+list(map(int, input().split()))
ans = -100*K

for i in range(1, N+1):
    temp[i] += temp[i-1]
    if i >= K:
        ans = max(ans, temp[i] - temp[i-K])

print(ans)
