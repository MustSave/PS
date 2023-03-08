import sys
input=sys.stdin.readline
print=sys.stdout.write

[N, M] = list(map(int, input().split()))
table = [[0]*(N+1)]+[[0] + list(map(int, input().split())) for _ in range(N)]
for i in range(1, N+1):
    for j in range(1, N+1):
        table[i][j] += table[i][j-1]
        table[i][j-1] += table[i-1][j-1]
        if j == N: table[i][N] += table[i-1][N]

for i in range(M):
    [x1, y1, x2, y2] = list(map(int, input().split()))
    ans = (table[x2][y2] - table[x1-1][y2]) - (table[x2][y1-1] - table[x1-1][y1-1])
    print(str(ans)+'\n')