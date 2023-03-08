N, K = map(int, input().split())

wvs = []
for _ in range(N):
    W, V = list(map(int, input().split()))
    wvs.append((W, V))

dp = [[0]*N for _ in range(K+1)] # N = 0부터 N까지 선택 가능, K = 배낭 무게


for i in range(N):
    for j in range(K+1):
        if j-wvs[i][0] >= 0:
            dp [j][i] = max(dp[j][i-1], dp[j-wvs[i][0]][i-1] + wvs[i][1])
        else:
            dp[j][i] = dp[j][i-1]

print(dp[K][N-1])