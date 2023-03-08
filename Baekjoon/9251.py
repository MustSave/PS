arr = [input(), input()]
length = [len(i) for i in arr]

dp = [[0 for _ in range(length[1]+1)] for _ in range(length[0]+1)]

for i in range(1, length[0]+1):
    for j in range(1, length[1]+1):
        if arr[0][i-1] == arr[1][j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[length[0]][length[1]])