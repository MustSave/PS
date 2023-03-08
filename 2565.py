N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
arr.sort(key=lambda x:x[0])
dp = []

for i in range(N):
    m = 0
    for j in range(i):
        if arr[j][1] < arr[i][1]:
            m = max(m, dp[j])
    dp.append(m+1)

print(N-max(dp))