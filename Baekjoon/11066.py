import sys;input=sys.stdin.readline;

def solve():
    K = int(input())
    chapter = [0]+list(map(int, input().split()))
    dp = [[1000000000 for _ in range(K)] for _ in range(K)]

    for i in range(K):
        dp[i][i] = 0
        chapter[i+1] += chapter[i]

# dp[0][K-1] = dp[0][j] + dp[j+1][K-1]
    for i in range(1, K): # 끝 챕터
        for j in range(i-1, -1, -1): # 시작 챕터
            for k in range(i-1, j-1, -1): # 중간 챕터 
                dp[j][i] = min(dp[j][i], dp[j][k] + dp[k+1][i] - chapter[j] + chapter[i+1])

    print(dp[0][K-1])

TC = int(input())
for _ in range(TC):
    solve()