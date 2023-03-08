N, S = map(int, input().split())
sums = [0]+list(map(int, input().split()))
for i in range(1, N+1): sums[i] += sums[i-1]
i, j, ans = 0, 1, N<<1

while j <= N and i < j:
    if sums[j] - sums[i] < S:
        j += 1
    else:
        ans = min(ans, j-i)
        i += 1

print(0 if ans == N<<1 else ans)