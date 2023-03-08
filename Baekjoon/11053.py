N = int(input())
arr = list(map(int, input().split()))
dp = []
ans = 1
for i in range(N):
    max_val = 0
    for j in range(i):
        if arr[i] > arr[j]:
            max_val = max(max_val, dp[j])
    dp.append(max_val+1)
    ans = max(ans, max_val+1)
print(ans)